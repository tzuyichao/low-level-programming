#include <stdio.h>

int ackerman(int m, int n) {
    if(m == 0) {
        return n+1;
    }
    if(n == 0) {
        return ackerman(m-1, 1);
    }
    return ackerman(m-1, ackerman(m, n-1));
}

int main() {
    printf("ackerman(3, 2): %d\n", ackerman(3, 2));
    return 0;
}