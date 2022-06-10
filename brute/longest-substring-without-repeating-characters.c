#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(char * s)
{
    int len = strlen(s);
    if(len == 0)
        return 0;
    int counter[len];
    for(int i=0; i<len; i++) {
        int l = 1;
        int check[256];
        for(int j=0; j<256; j++) {
            check[j] = 0;
        }
        check[s[i]] = 1;
        counter[i] = 1;
        for(int j=i+1; j<len; j++) {
            if(check[s[j]]) {
                counter[i] = l;
                break;
            } else {
                check[s[j]] = 1;
                ++l;
                counter[i] = l;
            }
        }
    }
    int res = 0;
    for(int i=0; i<len; i++) {
        if(counter[i] > res) {
            res = counter[i];
        }
    }
    
    return res;
}

void execute(char* s) 
{
    printf("%s lengthOfLongestSubstring = %d\n", s, lengthOfLongestSubstring(s));
}

int main() 
{
    char* s[] = {"abcabcbb", "bbbbb", "pwwkew"};
    for(int i=0; i<3; i++) {
        execute(s[i]);
    }
    return 0;
}