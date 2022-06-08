// 1332. Remove Palindromic Subsequences
// https://leetcode.com/problems/remove-palindromic-subsequences/

int isPalindrome(char *s)
{
    int l = strlen(s);
    for(int i=0; i<l; i++) {
        if(s[i] != s[l - i -1]) {
            return 0;
        }
    }
    return 1;
}

int removePalindromeSub(char * s){
    if(strlen(s) == 0)
        return 0;
    if(isPalindrome(s))
        return 1;
    return 2;
}