#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*) malloc(sizeof(int)*2);
    
    for(int i=0; i<numsSize-1; i++) {
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                *returnSize = 2;
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    *returnSize = 0;
    return res;
}

int main() {
    int nums[] = {3, 2, 4};
    int *returnSize;
    int* res = twoSum(nums, 3, 6, returnSize);
    for(int i=0; i<*returnSize; i++) {
        printf("%d\n", res[i]);
    }
    free(res);
    return 0;
}