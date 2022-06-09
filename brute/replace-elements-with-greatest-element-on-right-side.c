int findMax(int* nums, int numsSize, int start)
{
    if(start == numsSize) {
        return -1;
    }
    int max = nums[start];
    for(int i=start+1; i<numsSize; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
int* replaceElements(int* nums, int numsSize, int* returnSize)
{
    for(int i=0; i<numsSize; i++) {
        nums[i] = findMax(nums, numsSize, i+1);
    }
    *returnSize = numsSize;
    return nums;
}