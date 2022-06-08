#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int sidx = 0;
    int fidx = 1;
    int cur = nums[sidx];
    int d = 0;
    while(fidx < numsSize) {
        if(cur == nums[fidx]) {
            ++d;
        } else {
            nums[++sidx] = nums[fidx];
            cur =nums[fidx];
        }
        ++fidx;
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