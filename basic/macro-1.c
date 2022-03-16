// reference: Dr. Shiuh-Sheng Yu Web site
#include <stdio.h>

#define square(x) x * x
#define square2(x) (x) * (x)

int main() {
    int z = 3;
    printf("%d\n", square(z+1));
    printf("%d\n", square2(z+1));
    return 0;
}