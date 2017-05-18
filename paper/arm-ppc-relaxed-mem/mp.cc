/**
 *  Message passing
 *  ===============
 *
 *  An example of message passing by using std::thread.
 *
 *  Note: Compile with -pthread.
 */

#include <iostream>
#include <thread>

// Machine word.
char n = 0,
     flag = 1;

void
producer()
{
    n = 1; flag = 1;
}

void
consumer()
{
    while (flag == 0) { /* busy waiting */ }
    std::cout << "n=" << (int)n << std::endl;
}

int
main(int argc, const char *argv[])
{
    std::thread t1{producer}, t2{consumer};
    t1.join(); t2.join();
    return 0;
}
