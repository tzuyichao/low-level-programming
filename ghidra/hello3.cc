#include <cstdio>

void test(int i) {
    if(i > 5) {
        printf("above five");
    } else {
        printf("below five");
    }
}

int main() {
    auto a = 10;
    test(a);
}