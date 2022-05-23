#include <cstdio>

short increment_as_short(void* target) {
    auto as_short = static_cast<short*>(target);
    *as_short = *as_short + 1;
    return *as_short;
}

int main() {
    short base{665};
    auto mark_of_the_beast = increment_as_short(&base);
    printf("%d is the mark_of_the_beast. %d", mark_of_the_beast, base);
}