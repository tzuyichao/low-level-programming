#include <stdio.h>

// gcc -O3 volatile-2.c -o volative.exe -save-temps
int main()
{
    const volative int local = 10;
    int* ptr = (int*) &local;

    printf("Initial value of local: %d\n", local);

    *ptr = 100;
    printf("Modified value of local: %d\n", local);
    return 0;
}