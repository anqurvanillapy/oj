/**
 *  263. Ugly Number
 *
 *  Write a program to check whether a given number is an ugly number.
 *
 *  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *  For example, 6, 8 are ugly while 14 is not ugly since it includes another
 *  prime factor 7.
 *
 *  Note that 1 is typically treated as an ugly number.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isUgly(int n);

int
main(int argc, char const *argv[])
{
    printf("%d\n", isUgly(31));
    return 0;
}

/* === solution === */

bool
isUgly(int n)
{
    int i;
    int uglyfactor[3] = {2, 3, 5};

    if (n > 0 && n < 7) return true;
    if (n < 1) return false;

loop:
    while (n > 1) {
        for (i = 0; i < 3; ++i)
            if (n % uglyfactor[i] == 0) {
                n /= uglyfactor[i];
                goto loop;
            }
        return false;
    }

    return true;
}

/* === EOS === */
