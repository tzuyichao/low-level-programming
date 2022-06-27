
// 443. String Compression
// https://leetcode.com/problems/string-compression/
int compress(char* chars, int charsSize){
    int cur = 0;
    for(int i=0, j=0; i<charsSize; i=j)
    {
        while(j<charsSize && chars[i] == chars[j]) ++j;
        chars[cur++] = chars[i];
        if(j - i == 1) continue;
        char s[2000];
        sprintf(s, "%d", j-i);
        int l = strlen(s);
        for(int k=0; k<l; k++)
            chars[cur++] = s[k];
    }
    return cur;
}