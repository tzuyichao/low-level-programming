// 5. Longest Palindromic Substring

char * longestPalindrome(char * s){
    int len = strlen(s);
    int start = 0;
    int max = 1;
    
    int low = 0;
    int high = 0;
    
    for(int i=1; i<len; i++) {
        // case "abba"
        low = i-1;
        high = i;
        while((low >=0 && high <len) && s[low] == s[high]) {
            if(high - low + 1 > max) {
                start = low;
                max = high - low + 1;
            }
            low -= 1;
            high += 1;
        }
        
        // case "aabaa"
        low = i-1;
        high = i+1;
        while((low >= 0 && high < len) && s[low] == s[high]) {
            if(high - low + 1 > max) {
                start = low;
                max = high - low + 1;
            }
            low -= 1;
            high += 1;
        }
    }
    
    char* res = (char*)malloc((max+1) * sizeof(char));
    for(int i=start, pos=0; i<start+max; i++, pos++) {
        res[pos] = s[i];
    }
    res[max] = '\0';
    return res;
}