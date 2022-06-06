#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for(int i=0; i<numsSize; i++) {
        res[i] = nums[i] * nums[i];
    }

    qsort(res, numsSize, sizeof(int), cmpFunc);

    return res;
}

int main() 
{
    int size;
    int nums[] = {-7, -3, 2, 3, 11};
    int* res = sortedSquares(nums, 5, &size);

    for(int i=0; i<size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}