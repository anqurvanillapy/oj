#include <atomic>
#include <type_traits>
#include <cassert>
#include <iostream>
#include <thread>

#define LEN 100

template <typename T>
class bounded_mpmc_queue {
public:
    explicit bounded_mpmc_queue(std::size_t siz)
        : siz_(siz)
        , buf_mask_(siz - 1)
        , buf_(reinterpret_cast<node_t*>(new aligned_node_t[siz]))
    {
        // Power of two for modulo efficiency.
        assert(siz >= 2 && (siz & (siz - 1)) == 0);
        for (std::size_t i = 0; i < siz; ++i) buf_[i].seq.store(i,
                std::memory_order_relaxed);
        dequeue_pos_.store(0, std::memory_order_relaxed);
        enqueue_pos_.store(0, std::memory_order_relaxed);
    }

    ~bounded_mpmc_queue() { delete[] buf_; }

    // No copy and move.
    bounded_mpmc_queue(const bounded_mpmc_queue&) = delete;
    bounded_mpmc_queue& operator=(const bounded_mpmc_queue&) = delete;
    bounded_mpmc_queue(bounded_mpmc_queue&&) = delete;
    bounded_mpmc_queue& operator=(bounded_mpmc_queue&&) = delete;

    bool
    enqueue(const T& data)
    {
        node_t *cell;
        std::size_t pos = enqueue_pos_.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buf_[pos & buf_mask_];
            std::size_t seq = cell->seq.load(std::memory_order_acquire);
            // Ok for precision loss.
            intptr_t diff = (intptr_t)seq - (intptr_t)pos;

            if (diff == 0) {
                if (enqueue_pos_.compare_exchange_weak(pos, pos + 1,
                            std::memory_order_relaxed)) break;
            } else if (diff < 0) {
                return false;
            } else {
                pos = enqueue_pos_.load(std::memory_order_relaxed);
            }
        }

        cell->data = data;
        cell->seq.store(pos + 1, std::memory_order_release);
        return true;
    }

    bool
    dequeue(T& data)
    {
        node_t *cell;
        std::size_t pos = dequeue_pos_.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buf_[pos & buf_mask_];
            std::size_t seq = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = (intptr_t)seq - (intptr_t)(pos + 1);

            if (diff == 0) {
                if (dequeue_pos_.compare_exchange_weak(pos, pos + 1,
                            std::memory_order_relaxed)) break;
            } else if (diff < 0) {
                return false;
            } else {
                pos = dequeue_pos_.load(std::memory_order_relaxed);
            }
        }

        data = cell->data;
        cell->seq.store(pos + siz_, std::memory_order_release);
        return true;
    }
private:
    struct node_t {
        std::atomic_size_t seq;
        T data;
    };

    // Prevents false sharing.
    typedef typename std::aligned_storage<sizeof(node_t),
            std::alignment_of<node_t>::value>::type aligned_node_t;
    typedef char __cache_line_pad_t[64];

    __cache_line_pad_t pad0_{};
    const std::size_t siz_;
    const std::size_t buf_mask_;
    node_t* const buf_;
    __cache_line_pad_t pad1_{};
    std::atomic_size_t dequeue_pos_;
    __cache_line_pad_t pad2_{};
    std::atomic_size_t enqueue_pos_;
    __cache_line_pad_t pad3_{};
};

int
main()
{
    bounded_mpmc_queue<int> q(1024);

    std::thread t1([&] { for (int i = 0; i < LEN; ++i) q.enqueue(i); });
    std::thread t2([&] { for (int i = 0; i < LEN; ++i) q.enqueue(i); });
    std::thread t3([&] { for (int i = 0; i < LEN; ++i) q.enqueue(i); });
    t1.join();
    t2.join();
    t3.join();

    for (int i = 0; i < LEN * 3; ++i) {
        int n;
        if (!q.dequeue(n)) std::cout << "busy\n";
        std::cout << n << std::endl;
    }

    return 0;
}
