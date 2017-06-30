/**
 *  MT-safe counter
 *  ===============
 *
 *  A multithreading-safe counter in C++11.  I believe that using `static` for
 *  the mutex will guarantee a better performance.
 *
 *  Note: Compile with -std=c++11 -lpthread.
 */

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

class counter {
public:
    counter() = default;
    ~counter() = default;

    // In the book the copy ctor/assign optr are declared as private via
    // deriving from boost::noncopyable, but in C++11 it is more convenient to
    // use deleted functions.
    counter(const counter&) = delete;
    counter& operator=(const counter&) = delete;

    // const is not valid here since std::lock_guard discards this qualifier.
    int64_t
    val()
    {
        std::lock_guard<std::mutex> lock{mutex_};
        return val_;
    }

    void
    fetch_and_inc()
    {
        std::lock_guard<std::mutex> lock{mutex_};
        ++val_;
    }
private:
    int64_t val_{0};
    static std::mutex mutex_;
};

std::mutex counter::mutex_;

int
main(int argc, const char *argv[])
{
    counter c;
    std::vector<std::thread> workers;

    for (int i = 0; i < 420; ++i) {
        workers.emplace_back(std::thread{[&] () {
            c.fetch_and_inc();
        }});
    }

    for (auto& t : workers) t.join();

    // It's just so damn quick...
    std::cout << c.val() << std::endl;

    return 0;
}
