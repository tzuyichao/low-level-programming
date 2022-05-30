#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str[1000];
    int counter[10];
    int i;
    
    scanf("%s", str);
    
    for(i=0; i<10; i++) {
        counter[i] = 0;
    }

    printf("%d\n", strlen(str));
    for(i=0; i<strlen(str); ++i) {
        if(str[i] >= 48 && str[i] <= 57) {
            counter[str[i] - 48] += 1;
        }
    }

    for(int i=0; i<10; i++) {
        printf("%d ", counter[i]);
    }
    printf("\n");
    
    return 0;
}
