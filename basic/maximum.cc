#include <cstddef>
#include <cstdio>

int main() {
    unsigned long values[] = {10, 50, 20, 40, 0};
    unsigned long maximum = values[0];
    for(size_t i=1; i<5; i++) {
        if(values[i] > maximum) {
            maximum = values[i];
        }
    }
    printf("The maximum value is %lu", maximum);
}