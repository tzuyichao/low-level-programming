#include <stdio.h>

int B = 2;

void func(int *p) {
    printf("func: address of p %p value of p %d\n", p, *p);
    p = &B;
    printf("func: address of p %p value of p %d\n", p, *p);
}

int main() {
    int A = 1, C = 3;
    int *ptrA = &A;
    printf("address of ptrA %p value of ptrA %p\n", &ptrA, ptrA);
    func(ptrA);
    printf("after func() call, address of ptrA %p value of ptrA %p\n", &ptrA, ptrA);
    printf("%d\n", *ptrA);
    return 0;
}