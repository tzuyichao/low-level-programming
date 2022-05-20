#include <cstdio>
#include <vector>

using namespace std;

// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(auto i=1; i<m; i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }
        for(auto i=1; i<n; i++) {
            if(obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }
        for(auto i=1; i<m; i++) {
            for(auto j=1; j<n; j++) {
                if(obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    printf("Done.\n");
}