/**
 *  460. LFU Cache
 *
 *  Design and implement a data structure for Least Frequently Used (LFU) cache.
 *  It should support the following operations: get and put.
 *
 *  get(key) - Get the value (will always be positive) of the key if the key
 *  exists in the cache, otherwise return -1.
 *  put(key, value) - Set or insert the value if the key is not already present.
 *  When the cache reaches its capacity, it should invalidate the least
 *  frequently used item before inserting a new item. For the purpose of this
 *  problem, when there is a tie (i.e., two or more keys that have the same
 *  frequency), the least recently used key would be evicted.
 *
 *  - Follow up:
 *      + Could you do both operations in O(1) time complexity?
 */

#include <unordered_map>
#include <list>

class freq;

class freq_node {
public:
    freq_node(int f, freq_node *prev, freq_node *next)
        : f_(f), prev_(prev), next_(next)  { /* nop */ }
    ~freq_node() { /* nop */ }

    // No copy and move.
    freq_node(const freq_node&) = delete;
    freq_node& operator=(const freq_node&) = delete;
    freq_node(freq_node&&) = delete;
    freq_node& operator=(freq_node&&) = delete;

    friend freq;

    void
    add_key(int k)
    {
        kq_.emplace_back(k);
        auto it = kq_.end();
        if (!kq_.empty()) --it;
        kis_.emplace(k, it);
    }

    void
    remove_key(int k)
    {
        auto it = kis_[k];
        kis_.erase(k);
        kq_.erase(it);
    }

    int
    remove_last_key()
    {
        int k = kq_.front();
        kis_.erase(k);
        kq_.pop_front();
        return k;
    }
private:
    int f_;
    freq_node *prev_;
    freq_node *next_;
    std::list<int> kq_;
    std::unordered_map<int, typename std::list<int>::iterator> kis_;
};

class freq {
public:
    freq() : head_(NULL), tail_(NULL) { /* nop */ };
    ~freq() { /* nop */ }

    // No copy and move.
    freq(const freq&) = delete;
    freq& operator=(const freq&) = delete;
    freq(freq&&) = delete;
    freq& operator=(freq&&) = delete;

    void
    add_last(int k)
    {
        if (head_ == NULL) head_ = tail_ = new freq_node(1, NULL, NULL);
        if (tail_->f_ != 1) {
            auto temp = new freq_node(1, tail_, NULL);
            tail_->next_ = temp;
            tail_ = temp;
        }
        tail_->add_key(k);
        kfs_.emplace(k, tail_);
    }

    void
    inc(int k)
    {
        auto n = kfs_[k];
        n->remove_key(k);
        kfs_.erase(k);

        if (head_ == n) {
            auto temp = new freq_node(n->f_ + 1, NULL, head_);
            head_->prev_ = temp;
            head_ = temp;
            head_->next_ = n;
            kfs_.emplace(k, head_);
            head_->add_key(k);
        } else if (n->prev_->f_ != n->f_ + 1) {
            auto temp = new freq_node(n->f_ + 1, n->prev_, n);
            n->prev_ = temp;
            n->prev_->next_ = temp;
            kfs_.emplace(k, temp);
            temp->add_key(k);
        } else {
            kfs_.emplace(k, n->prev_);
            n->prev_->add_key(k);
        }

        if (n->kq_.empty()) {
            if (n == tail_) {
                tail_ = n->prev_;
                tail_->next_ = NULL;
            } else {
                n->prev_->next_ = n->next_;
                n->next_->prev_ = n->prev_;
            }
            delete n;
        }
    }

    int 
    remove_last()
    {
        int k = tail_->remove_last_key();
        if (tail_->kq_.empty()) {
            tail_ = tail_->prev_;
            delete tail_->next_;
            tail_->next_ = NULL;
        }
        return k;
    }
private:
    freq_node *head_;
    freq_node *tail_;
    std::unordered_map<int, freq_node*> kfs_;
};

class LFUCache {
public:
    LFUCache() : capacity_(2) { /* nop */ }
    explicit LFUCache(int capacity) : capacity_(capacity) { /* nop */ }
    ~LFUCache() { /* nop */ }

    // No copy and move.
    LFUCache(const LFUCache&) = delete;
    LFUCache& operator=(const LFUCache&) = delete;
    LFUCache(LFUCache&&) = delete;
    LFUCache& operator=(LFUCache&&) = delete;

    int 
    get(int k)
    {
        if (kvs_.find(k) == kvs_.end()) {
            return -1;
        } else {
            int v = kvs_[k];
            fq_.inc(k);
            return v;
        }
    }

    void
    put(int k, int v)
    {
        if (kvs_.find(k) == kvs_.end()) {
            fq_.add_last(k);
            kvs_.emplace(k, v);
        } else kvs_[k] = v;

        if (siz_ + 1 > capacity_) {
            int k = fq_.remove_last();
            kvs_.erase(k);
        } else ++siz_;
    }
private:
    unsigned siz_{0};
    unsigned capacity_;
    std::unordered_map<int, int> kvs_;
    freq fq_;
};
