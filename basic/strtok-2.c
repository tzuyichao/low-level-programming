#include <stdio.h>
#include <string.h>

int main() {
    char *str = "Hello world, nice to meet you";
    char str2[64];
    strcpy(str2, str);

    const char *d = " ,";
    char *p;

    p = strtok(str, d);
    while(p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, d);
    }

    printf("----\n");
    printf("%s\n", str);
    printf("%s\n", str2);
    
    return 0;
}