#include <stdio.h>
#include <stdlib.h>

int thirdMax(int* nums, int numsSize)
{
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    for (int i=0; i<numsSize; i++) {
        int num = nums[i];
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second && num < first) {
            third = second;
            second = num;
        } else if (num > third && num < second) {
            third = num;
        }
    }
    return (third == LONG_MIN || third == second) ? first : third;
}

int main()
{
    int nums[] = {3,2,1};

    printf("%d\n", thirdMax(nums, 4));
    return 0;
}