/**
 *  27. Remove Element
 *
 *  Given an array and a value, remove all instances of that value in place and
 *  return the new length.
 *
 *  Do not allocate extra space for another array, you must do this in place
 *  with constant memory.
 *
 *  The order of elements can be changed. It doesn't matter what you leave
 *  beyond the new length.
 *
 *  - Example:
 *      + Given input array nums = [3,2,2,3], val = 3. Your function should
 *      return length = 2, with the first two elements of nums being 2.
 *  - Hints:
 *      + Try two pointers.
 *      + Did you use the property of "the order of elements can be changed"?
 *      + What happens when the elements to remove are rare?
 */

#include <stdio.h>
#define ARRSIZE 8

int removeElement(int* nums, int numsSize, int val);

int
main(int argc, char const *argv[])
{
    int nums[ARRSIZE] = {1, 2, 3, 3, 5, 6, 7, 7};
    int val = 3;
    int numsSize = ARRSIZE;
    int i;

    int _len = removeElement(nums, numsSize, val);
    printf("new nums: ");
    for (i = 0; i < _len; i++) printf("%d ", nums[i]);
    printf("\nnew length: %d\n", _len);

    return 0;
}

/* === solution === */

int
removeElement(int* nums, int numsSize, int val)
{
    int _len = numsSize, temp, *top, *t;

    for (top = t = &nums[numsSize-1]; t >= &nums[0]; t--) {
        if (*t == val) {
            temp = *t; *t = *top; *top = temp;
            top--; _len--;
        }
    }

    return _len;
}

/* === EOS === */
