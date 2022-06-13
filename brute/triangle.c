#include <limits.h>

int min(int a, int b) {
    return a > b?b:a;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int n = triangleColSize[triangleSize-1];
    int dp[triangleSize][n];

    dp[0][0] = triangle[0][0];
    for(int i=1; i<triangleSize; i++)
        dp[i][0] = triangle[i][0] + dp[i-1][0];
    
    for(int i=1; i<n; i++)
        dp[i][i] = triangle[i][i] + dp[i-1][i-1];

    for(int i=2; i<triangleSize; i++) {
        for(int j=1; j<i; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
        }
    }
    int res = INT_MAX;
    for(int i=0; i<n; i++) {
        if(dp[triangleSize-1][i] < res)
            res = dp[triangleSize-1][i];
    }
    return res;
}