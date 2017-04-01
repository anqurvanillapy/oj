#include "myods.h"

int
main(int argc, const char *argv[])
{
    myods::array_stack<int> s;
    s.push(1); s.push(2); s.push(3);
    std::cout << "array_stack:" << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    myods::fast_array_stack<int> fs;
    fs.push(1); fs.push(2); fs.push(3);
    std::cout << "fast_array_stack:" << std::endl;
    std::cout << fs.pop() << std::endl;
    std::cout << fs.pop() << std::endl;
    std::cout << fs.pop() << std::endl;

    myods::array_queue<int> q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    std::cout << "array_queue:" << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;

    myods::array_deque<int> deq;
    deq.enqueue(1); deq.enqueue(2); deq.enqueue(3);
    std::cout << "array_deque: (as a queue)" << std::endl;
    std::cout << deq.dequeue() << std::endl;
    std::cout << deq.dequeue() << std::endl;
    std::cout << deq.dequeue() << std::endl;
    deq.push(1); deq.push(2); deq.push(3);
    std::cout << "array_deque: (as a stack)" << std::endl;
    std::cout << deq.pop() << std::endl;
    std::cout << deq.pop() << std::endl;
    std::cout << deq.pop() << std::endl;

    myods::dual_array_deque<int> dual_deq;
    dual_deq.enqueue(1); dual_deq.enqueue(2); dual_deq.enqueue(3);
    std::cout << "dual_array_deque: (as a queue)" << std::endl;
    std::cout << dual_deq.dequeue() << std::endl;
    std::cout << dual_deq.dequeue() << std::endl;
    std::cout << dual_deq.dequeue() << std::endl;
    dual_deq.push(1); dual_deq.push(2); dual_deq.push(3);
    std::cout << "dual_array_deque: (as a stack)" << std::endl;
    std::cout << dual_deq.pop() << std::endl;
    std::cout << dual_deq.pop() << std::endl;
    std::cout << dual_deq.pop() << std::endl;

    myods::rootish_array_stack<int> rs;
    rs.push(1); rs.push(2); rs.push(3);
    std::cout << "rootish_array_stack:" << std::endl;
    std::cout << rs.pop() << std::endl;
    std::cout << rs.pop() << std::endl;
    std::cout << rs.pop() << std::endl;

    return 0;
}
