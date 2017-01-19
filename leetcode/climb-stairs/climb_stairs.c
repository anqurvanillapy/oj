/**
 *  70. Climbing Stairs
 *
 *  You are climbing a stair case. It takes n steps to reach to the top.
 *
 *  Each time you can either climb 1 or 2 steps. In how many distinct ways can
 *  you climb to the top?
 *
 *  Note: Given n will be a positive integer.
 *
 *  Tags: Dynamic programming
 */

#include <stdio.h>

int climbStairs(int n);
int step1(int n);
int step2(int n);

int
main(int argc, const char *argv[])
{
    int n = 4;
    printf("%d\n", climbStairs(n));

    return 0;
}

/* === solution === */

/**
 *  TLE: Recursion
 */

// int
// climbStairs(int n)
// {
//     return step1(n) + step2(n);
// }

// int
// step1(int n)
// {
//     if (n < 2) return 1;
//     return step1(n - 1) + step2(n - 1);
// }

// int
// step2(int n)
// {
//     if (n < 2) return 0;
//     return step1(n - 2) + step2(n - 2);
// }

/* === EOS === */
