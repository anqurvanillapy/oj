/**
 *  191. Number of 1 Bits
 *
 *  Write a function that takes an unsigned integer and returns the number of
 *  '1' bits it has (also known as the Hamming weight).
 *
 *  For example, the 32-bit integer ’11' has binary representation
 *  00000000000000000000000000001011, so the function should return 3.
 */

#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n);

int
main(int argc, const char *argv[])
{
    int n = 127;
    printf("%d\n", hammingWeight(n));

    return 0;
}

/* === solution === */

int
hammingWeight(uint32_t n)
{
    int i, count = 0;
    uint32_t mask = 1;

    if (n == 0 || n == 1) return n;

    for (i = 0; i < 32; ++i) {
        if (n & mask) count++;
        n >>= 1;
    }

    return count;
}

/* === EOS === */
