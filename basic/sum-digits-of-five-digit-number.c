#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int res = 0;
    
    for(int i=4; i>=0; i--) {
        int b = (int)pow(10, i);
        res += n/b;
        n = n % b;
    }
    
    printf("%d", res);
    return 0;
}