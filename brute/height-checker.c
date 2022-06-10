#include <stdio.h>
#include <stdlib.h>

int compFunc(const void* left, const void* right) 
{
    return *((int*)left) - *((int*)right);
}

int heightChecker(int* heights, int heightsSize)
{
    int* clone = (int*)malloc(heightsSize * sizeof(int));
    for(int i=0; i<heightsSize; i++) {
        clone[i] = heights[i];
    }
    qsort(clone, heightsSize, sizeof(int), compFunc);
    int res = 0;
    for(int i=0; i<heightsSize; i++) {
        if(clone[i] != heights[i])
            ++res;
    }

    free(clone);
    return res;
}

int main() 
{
    int data[] = {1,2,3,4,5};
    int res = heightChecker(data, 6);
    printf("heightChecker: %d\n", res);

    return 0;
}