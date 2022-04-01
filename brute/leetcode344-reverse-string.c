#include <stdio.h>
#include <string.h>

/**
 * 344. Reverse String
 * https://leetcode.com/problems/reverse-string/
 * 
 * Runtime: 48 ms, faster than 92.38% of C online submissions for Reverse String.
 * Memory Usage: 12.5 MB, less than 40.64% of C online submissions for Reverse String.
 * 
 * @file leetcode344-reverse-string.c
 * @author tzuyichao
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
void reverseString(char* s, int sSize){
    for(int i=0; i<sSize/2; i++) {
        char tmp = *(s + i);
        *(s + i) = *(s + (sSize-1-i));
        *(s + (sSize-1-i)) = tmp;
    }
}

void main() {
    char pString[6] = "hello";
    printf("%d\n", strlen(pString));
    reverseString(pString, strlen(pString));
    
    printf("%s\n", pString);
}