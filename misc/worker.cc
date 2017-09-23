#include <iostream>
#include <deque>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::deque<std::function<void()>> tasks;
std::mutex t_mtx;
std::condition_variable cv;

class worker {
public:
    worker() = default;
    ~worker() = default;

    void operator()() { while (true) poll(); }

    void
    push_back(const std::function<void()>& f)
    {
        {
            std::lock_guard<std::mutex> lk(t_mtx);
            tasks.push_back(f);
        }
        cv.notify_all();
    }

    std::function<void()>
    pop_front()
    {
        std::lock_guard<std::mutex> lk(t_mtx);
        auto ret = tasks.front();
        tasks.pop_front();
        return ret;
    }

    void
    poll()
    {
        std::unique_lock<std::mutex> lk(t_mtx);
        cv.wait(lk, [&]{ return !tasks.empty(); });
        lk.unlock();

        auto t = pop_front();
        t();
    }
};

int
main(int argc, const char *argv[])
{
    worker w;
    std::thread t1(w);

    w.push_back([&] { std::cout << "good\n"; });
    w.push_back([&] { std::cout << "luck\n"; });
    std::this_thread::sleep_for(std::chrono::milliseconds(420));
    w.push_back([&] { std::cout << "have\n"; });
    w.push_back([&] { std::cout << "fun\n"; });

    t1.join();
    return 0;
}
