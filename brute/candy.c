
// 135. Candy
// https://leetcode.com/problems/candy/
// https://www.cnblogs.com/grandyang/p/4575026.html
int candy(int* ratings, int ratingsSize){
    int res = 0;
    int nums[ratingsSize];
    for(int i=0; i<ratingsSize; i++) nums[i] = 1;
    
    for(int i=0; i<ratingsSize-1; i++) 
    {
        if(ratings[i+1] > ratings[i]) nums[i+1] = nums[i] + 1;
    }
    for(int i=ratingsSize-1; i>0; i--)
    {
        if(ratings[i-1] > ratings[i]) nums[i-1] = max(nums[i-1], nums[i]+1);
    }
    for(int i=0; i<ratingsSize; i++)
    {
        res += nums[i];
    }
    
    return res;
}

int max(int a, int b) 
{
    return a>b?a:b;
}