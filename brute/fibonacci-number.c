// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
int fib(int n){
    // +2 for n=0, 1 case
    int dp[n+2];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}