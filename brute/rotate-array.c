// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// Time Limit Exceeded
void rrotate(int* nums, int numsSize)
{
    int tmp = nums[numsSize-1];
    for(int i=numsSize-1; i>0; i--)
    {
        nums[i] = nums[i-1];
    }
    nums[0] = tmp;
}

void rotate(int* nums, int numsSize, int k)
{
    for(int i=0; i<k; i++)
        rrotate(nums, numsSize);
}