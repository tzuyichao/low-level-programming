int max(int a, int b) {
    return a>b?a:b;
}

// 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
int longestValidParentheses(char * s){
    int left = 0;
    int right = 0;
    int l = strlen(s);
    int i;
    int res = 0;
    for(i=0; i<l; i++) {
        if(s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if(right == left) {
            res = max(res, 2*left);
        } else if(right > left) {
            left = 0;
            right = 0;
        }
    }
    left = 0;
    right = 0;
    for(i=l-1; i>=0; i--) {
        if(s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if(right == left) {
            res = max(res, 2*left);
        } else if(left > right) {
            left = 0;
            right = 0;
        }
    }
    return res;
}