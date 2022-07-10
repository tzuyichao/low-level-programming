
// https://leetcode.com/problems/jump-game/
bool canJump(int* nums, int numsSize){
    int m = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(i > m) return false;
        if(m > numsSize) return true;
        m = max(m, nums[i] + i);
    }
    return true;
}

int max(int a, int b)
{
    return a > b?a:b;
}