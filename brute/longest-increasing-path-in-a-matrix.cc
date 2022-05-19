#include <cstdio>
#include <vector>

using namespace std;

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int res = 0;
        for(int y=0; y<m; y++) {
            for(int x=0; x<n; x++) {
                res = max(res, dfs(matrix, x, y));
            }
        }
        return res;
    }
private:
    int m;
    int n;
    vector<vector<int>> dp;
    int dfs(const vector<vector<int>>& matrix, int x, int y) {
        if(dp[y][x] != -1) return dp[y][x];
        static int dirs[] = {0, -1, 0, 1, 0};
        dp[y][x] = 1;
        for(int i=0; i<4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i+1];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m || matrix[ty][tx] <= matrix[y][x]) {
                continue;
            }
            dp[y][x] = max(dp[y][x], 1+dfs(matrix, tx, ty));
        }
        return dp[y][x];
    }
};

int main() {
    printf("Done.\n");
}