// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// v1: Time Limit Exceeded
// v2: pass

void rotate(int* nums, int numsSize, int k)
{
    if(k % numsSize == 0) return;
    
    int step = k % numsSize;
    int temp[numsSize];
    for(int i=0; i<numsSize; i++)
        temp[(i+step)%numsSize] = nums[i];
    for(int i=0; i<numsSize; i++)
        nums[i] = temp[i];
}