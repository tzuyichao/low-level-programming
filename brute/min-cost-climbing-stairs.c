// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
// 每次只能走一或二步，所以dp式就是
//     dp[i] = min(dp[i-2] + cost[i-2], dp[i-1]+cost[i-1])


int minCostClimbingStairs(int* cost, int costSize)
{
    int* dp = (int*)malloc((costSize+1) * sizeof(int));
    for(int i=0; i<costSize+1; i++) dp[i] = 0;
    for(int i=2; i<costSize+1; i++)
        dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
    
    int res = dp[costSize];
    free(dp);
    return res;
}

int min(int a, int b) {
    return a > b?b:a;
}