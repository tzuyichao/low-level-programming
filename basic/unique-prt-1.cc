#include <memory>
#include <iostream>

struct Foundation {
    const char* founder;
};

int main() {
    std::unique_ptr<Foundation> second_foundation{new Foundation{}};
    second_foundation->founder = "Wanda";
    
    std::cout << second_foundation->founder << std::endl;

    return 0;
}