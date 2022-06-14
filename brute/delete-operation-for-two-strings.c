
// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/
// 就Edit Distance，cost 是 2
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i=1; i<m+1; i++) {
        dp[i][0] = i;
    }
    
    for(int i=1; i<n+1; i++) {
        dp[0][i] = i;
    }
    
    for(int i=1; i<m+1; i++) {
        for(int j=1; j<n+1; j++) {
            int sub;
          //  printf("%d %d\n", word1[i-1], word2[j-1]);
            if(word1[i-1] == word2[j-1]) {
                sub = 0;
            } else {
                sub = 2;
            }
            dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + sub);
            
        }
    }
    
    
    // for(int i=0; i<m+1; i++) {
    //     for(int j=0; j<n+1; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return dp[m][n];
}

int min(int a, int b)
{
    return a>b?b:a;
}