#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int r=3, c=4, i, j, count;

    int (*arr)[r][c] = malloc(sizeof *arr);
    
    count = 0;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            (*arr)[i][j] = ++count;
    
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            printf("%d ", (*arr)[i][j]);
    
    free(arr);
    return 0;
}