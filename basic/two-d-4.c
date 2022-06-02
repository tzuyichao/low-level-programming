#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int r=3, c=4, len=0;
    int *ptr, **arr;
    int count = 0, i, j;

    len = sizeof(int*) * r + sizeof(int) * c * r;
    arr = (int**)malloc(len);

    ptr = (int*)(arr + r);

    // 第一維內容指向第二維位置
    for(i=0; i<r; i++)
        arr[i] = (ptr + c * i);
    
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            arr[i][j] = ++count;
    
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    free(arr);
    return 0;
}