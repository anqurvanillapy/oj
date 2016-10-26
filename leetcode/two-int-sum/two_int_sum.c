/**
 *  371. Sum of Two Integers
 *
 *  Calculate the sum of two integers a and b, but you are not allowed to use
 *  the operator + and -.
 *
 *  - Example:
 *      + Given a = 1 and b = 2, return 3.
 */

#include <stdio.h>

int getSum(int a, int b);

int
main(int argc, char const *argv[])
{
    int sum, a = -9, b = -1;

    sum = getSum(a, b);
    printf("%d\n", sum);

    return 0;
}

/* === solution === */

int
getSum(int a, int b)
{
    int i, j, oi, oj, x, y;
    int max, carry, offset, sum;

    i = a; j = b;
    carry = offset = sum = 0;
    max = i > j ? i : j;
    do {
        oi = i >> offset; oj = j >> offset;
        x = oi & 1; y = oj & 1;
        sum = sum | ((carry ^ x ^ y) << offset);
        carry = (carry & x) | (carry & y) | (x & y);
        offset++;
    } while (offset < 32);

    return sum;
}

/* === EOS === */
