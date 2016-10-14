/**
 *  189. Rotate Array
 *
 *  Rotate an array of n elements to the right by k steps.
 * 
 *  - Example:
 *      + With n = 7 and k = 3, the array `[1,2,3,4,5,6,7]` is rotated to
 *      `[5,6,7,1,2,3,4]`.
 * - Follow up:
 *      + Could you do it in-place with O(1) extra space?
 */

#include <stdio.h>

void rotate(int* arr, int numsSize, int k);

int
main(int argc, char const *argv[])
{
    int i, len;
    int arr[] = {1, 2, 3, 4, 5, 6};

    len = sizeof(arr) / sizeof(int);
    rotate(&arr, len, 4);
    printf("arrlen=%d\n", len);
    printf("output=");
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/* === solution === */

/**
 *  O(n*k) time, O(1) space
 */

// void
// rotate(int* nums, int numsSize, int k)
// {
//     int temp, i, j;
//     for (i = 0; i < k; i++)
//         for (j = 0; j < numsSize; j++) {
//             temp = nums[j];
//             nums[j] = nums[numsSize-1];
//             nums[numsSize-1] = temp;
//         }
// }

/**
 *  O(n) time, O(1) space
 */

void
rotate(int* nums, int numsSize, int k)
{
    int i, count = 0;

    for (i = 0; count < numsSize; i++) {
        int step, tail, last, temp;

        step = (numsSize - k % numsSize) % numsSize;
        tail = i + step;

        do {
            last = (tail + step) % numsSize;
            temp = nums[tail];
            nums[tail] = nums[last];
            nums[last] = temp;
            tail = last;
            count++;
        } while (tail != i);

        count++;
    }
}

/* === EOS === */
