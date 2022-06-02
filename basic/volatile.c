#include <stdio.h>

// without optimization
// gcc -O3 volatile.c -o volative.exe -save-temps
// 
// with optimization
// gcc volatile.c -o volative.exe -save-temps
int main()
{
    const int local = 10;
    int* ptr = (int*) &local;

    printf("Initial value of local: %d\n", local);

    *ptr = 100;
    printf("Modified value of local: %d\n", local);
    return 0;
}