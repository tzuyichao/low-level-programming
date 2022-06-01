/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* res = (int*) malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    *res = *nums;
    for(int i=1; i<numsSize; i++) {
        *(res+i) = *(res+i-1) + *(nums+i);
    }
    
    return res;
}