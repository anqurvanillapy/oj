/**
 *  1. Two Sum
 *
 *  Given an array of integers, return indices of the two numbers such that they
 *  add up to a specific target. You may assume that each input would have
 *  exactly one solution. The return format should be zero-based indices.
 *
 *  - Example:
 *      + Given nums = [2, 7, 11, 15], target = 9, because nums[0] + nums[1] =
 *      2 + 7 = 9, so return [0, 1].
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 4

int* twoSum(int* nums, int numsSize, int target);

int
main(int argc, char const *argv[])
{
    // Unsorted.
    int nums[ARRSIZE] = {3, 2, 4, 5};
    // Sorted.
    // int nums[ARRSIZE] = {1, 2, 4, 4};
    int numsSize = ARRSIZE;
    int target = 8;
    int *result = NULL;
    int i;

    result = twoSum(nums, numsSize, target);
    printf("[%d, %d]\n", result[0], result[1]);
    free(result);

    return 0;
}

/* === solution === */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/// Quadratic.  Better solution is using a hash map.

int *
twoSum(int* nums, int numsSize, int target)
{
    int i, j, _target = target;
    int *result = (int *)malloc(2 * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == _target) {
                result[0] = i;
                result[1] = j;
                goto end;
            }
        }
    }
    result[0] = result[1] = 0;
end:
    return result;
}

/* === EOS === */
