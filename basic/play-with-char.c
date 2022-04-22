#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    char s[100];
    char sen[100];
    
    scanf("%c", &c);
    scanf("%s", &s);
    scanf("\n");
    scanf("%[^\n]%*c", sen);
    
    printf("%c\n", c);
    printf("%s\n", s);
    printf("%s\n", sen);
    return 0;
}