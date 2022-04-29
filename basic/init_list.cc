#include <cstdio>

struct ClockOfTheLongNow {
    long year;

    ClockOfTheLongNow(long y) : year{y} {
    }

    long get_year() const {
        return year;
    }
    void set_year(long y) {
        year = y;
    }
};

struct Avoat {
    Avoat(const char* name, long year_of_apert) : name{name}, apert{year_of_apert} {}
    void announce() const {
        printf("My name is %s and my text apert is %d.\n", name, apert.get_year());
    }
    const char* name;
    ClockOfTheLongNow apert;
};

int main() {
    Avoat raz{"Erasmas", 3010};
    Avoat jad{"Jad", 4000};
    raz.announce();
    jad.announce();
}