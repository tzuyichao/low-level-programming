#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/ 1
int main()
{
    int r = 3, c = 4;

    int* ptr = (int*)malloc((r*c)*sizeof(int));

    for(int i=0; i<r*c; ++i) {
        ptr[i] = i+1;
    }

    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            printf("%d ", ptr[i*c+j]);
        }
        printf("\n");
    }
    free(ptr);

    return 0;
}