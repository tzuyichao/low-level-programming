#include <stdio.h>
#include <stdlib.h>

void move(int* nums, int numsSize, int idx) 
{
    int tmp = nums[idx];
    int i;
    for(i=idx; i<numsSize-1; i++) {
        nums[i] = nums[i+1];
    }
    nums[i] = tmp;
}

int removeDuplicates(int* nums, int numsSize)
{
    int cur = nums[0];
    int d = 0;
    for(int i=1; i<numsSize; i++) {
        if(nums[i] == cur) {
            nums[i] = 101;
            ++d;
        } else {
            cur = nums[i];
        }
    }
    int m = 0;
    int idx = 0;
    while(m != d) {
        if(nums[idx] == 101) {
            move(nums, numsSize, idx);
            ++m;
        } else {
            ++idx;
        }
    }
    return numsSize-d;
}

int main()
{
    int nums[] = {1, 1, 1, 2};
    int r = removeDuplicates(nums, 4);
    for(int i=0; i<r; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}