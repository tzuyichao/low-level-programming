#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        res += arr[i];
    }
    printf("%d", res);

    return 0;
}