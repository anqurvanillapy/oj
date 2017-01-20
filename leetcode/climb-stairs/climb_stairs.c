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

// int step1(int n);
// int step2(int n);

double combinate(double n, double k);
double permute(double n, double k);

int
main(int argc, const char *argv[])
{
    int n = 27;
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

/**
 *  AC (poorly): Using the formula of combinations and permutations
 */

int
climbStairs(int n)
{
    double count = 1;
    double dual, mono;

    for (dual = 1; dual <= n / 2; ++dual) {
        mono = n - dual * 2;
        count += (dual < mono) ? combinate(dual + mono, mono) : combinate(dual + mono, dual);
    }

    return (int)count;
}

double
combinate(double n, double k)
{
    if (k == 0 || n == k) return 1;
    if (k > n / 2) k = n - k;
    return permute(n, k) / permute(k, k);
}

double
permute(double n, double k)
{
    double i, j, ret = 1;
    for (i = n, j = 0; j < k; --i, ++j) ret *= i;
    return ret;
}

/* === EOS === */
