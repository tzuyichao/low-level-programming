// 1984. Minimum Difference Between Highest and Lowest of K Scores
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1984-minimum-difference-between-highest-and-lowest-of-k-scores/
int cmp(const void *a, const void *b)
{
    return *(const int*)a - *(const int*)b;
}

int min(int a, int b)
{
    return a > b?b:a;
}

int minimumDifference(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = INT_MAX;
    for(int i=k-1; i<numsSize; i++)
    {
        res = min(res, nums[i] - nums[i-k+1]);
    }
    return res;
}