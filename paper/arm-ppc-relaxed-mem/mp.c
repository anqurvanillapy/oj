/**
 *  Message passing
 *  ===============
 *
 *  An example of message passing that would possibly fail due to OoOE
 *  (out-of-order execution).  Note that using std::thread in C++ library would
 *  generate much more assembly code than C, and sometimes outputs the wrong and
 *  forbidden result (n=0) as well.  BTW, __asm__ __volatile__ ("":::"memory")
 *  only guarantees the compile-time out-of-order execution, instead of placing
 *  some memory barriers.
 *
 *  Note: Compile with -pthread.
 */

#include <stdio.h>
#include <pthread.h>

// Machine word.
char n = 0,
     flag = 1;

void *
producer()
{
    n = 1; flag = 1;
    pthread_exit(NULL);
}

void *
consumer()
{
    while (flag == 0) { /* busy waiting */ }
    printf("n=%d\n", n);
    pthread_exit(NULL);
}

int
main(int argc, const char *argv[])
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL); pthread_join(t2, NULL);
    return 0;
}
