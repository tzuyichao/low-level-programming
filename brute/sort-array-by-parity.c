#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    if(numsSize > 1) {
        int e = 0;
        while(e < numsSize && nums[e]%2 == 0) {
            ++e;
        }
        int o = numsSize-1;
        while(o > 0 && nums[o]%2 == 1) {
            --o;
        }
        while(e < o) {
            if(nums[e]%2 == 1 && nums[o]%2 == 0) {
                int tmp = nums[o];
                nums[o] = nums[e];
                nums[e] = tmp;
                ++e;
                --o;
            } else if(nums[e]%2 == 1 && nums[o]%2 == 1) {
                --o;
            } else {
                ++e;
            }
        }
    } 
    for(int i=0; i<numsSize; i++) {
        res[i] = nums[i];
    }
    
    return res;
}

int main() 
{
    int arr[] = {1,3,0,5,2};
    int l;
    int* res = sortArrayByParity(arr, 5, &l);

    for(int i=0; i<l; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}