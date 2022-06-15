// 1048. Longest String Chain
// https://leetcode.com/problems/longest-string-chain/
// 對題目的了解就是連續字距是一的最大長度
// 作法
// 1. 就是先按照字串長度排序好
// 2. 然後DP就是字串陣列的長度的array，初始為1
// 3. 從第二個開始，往前找最長字距是1，走的過程把最大值留下來回答用
int compFunc(const void *a, const void *b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int max(int a, int b) {
    return a>b?a:b;
}

int min(int a, int b)
{
    return a>b?b:a;
}

int helper(char *word1, char *word2) {
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
    return dp[m][n];
}

int longestStrChain(char ** words, int wordsSize){
    qsort(words, wordsSize, sizeof(char*), compFunc);
    for(int i=0; i<wordsSize; i++) {
        printf("%s\n", words[i]);
    }
    int res = 1;
    int dp[wordsSize];
    for(int i=0; i<wordsSize; i++)
        dp[i] = 1;
    for(int i=1; i<wordsSize; i++) {
        for(int j=i-1; j>=0; j--) {
            int m = strlen(words[j]);
            int n = strlen(words[i]);
            if(m+1 < n)
                break;
            if(m == n)
                continue;
            if(helper(words[j], words[i]) == 1) {
                dp[i] = max(dp[i], dp[j]+1);
                if(res < dp[i]) 
                    res = dp[i];
            }
        }
    }
    
    return res;
}

