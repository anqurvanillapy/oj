/**
 *  202. Happy Number
 *
 *  
 *  Write an algorithm to determine if a number is "happy".
 *
 *  A happy number is a number defined by the following process: Starting with
 *  any positive integer, replace the number by the sum of the squares of its
 *  digits, and repeat the process until the number equals 1 (where it will
 *  stay), or it loops endlessly in a cycle which does not include 1. Those
 *  numbers for which this process ends in 1 are happy numbers.
 *
 *  Example: 19 is a happy number
 *
 *    1 ** 2 + 9 ** 2 = 82
 *    8 ** 2 + 2 ** 2 = 68
 *    6 ** 2 + 8 ** 2 = 100
 *    1 ** 2 + 0 ** 2 + 0 ** 2 = 1
 *
 *  Tags: Hash Table, Math
 */

#include <stdio.h>
#include <stdbool.h>

bool isHappy(int n);

int
main(int argc, const char *argv[])
{
    int n = 13;
    printf("%d\n", isHappy(n));

    return 0;
}

/* === solution === */

bool
isHappy(int n)
{
    int squares_table[162];
    int m;
    int rem, sum;

    for (m = 0; m < 162; ++m) squares_table[m] = 0;

    m = n;
    for (;;) {
        sum = 0;
        for (;;) {
            rem = m % 10; 
            m /= 10;
            sum += rem * rem;

            if (m == 0) {
                if (sum == 1) return true;

                if (sum < 162) {
                    if (squares_table[sum] == 1) return false;
                    else squares_table[sum] = 1;
                }

                m = sum;
                break;
            }
        }
    }
}

/* === EOS === */
