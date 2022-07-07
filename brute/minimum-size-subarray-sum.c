// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// [sliding window]
int minSubArrayLen(int target, int* nums, int numsSize){
    int sum = 0;
    int start = 0;
    int minWindowSize = INT_MAX;
    
    for(int end=0; end<numsSize; end++)
    {
        sum += nums[end];
        while(sum >= target)
        {
            minWindowSize = min(minWindowSize, end-start+1);
            sum -= nums[start++];
        }
    }
    
    return minWindowSize==INT_MAX?0:minWindowSize;
}

int min(int a, int b)
{
    return a>b?b:a;
}