#include <iostream>

auto add(auto a, auto b) {
    return a + b;
}

int main() {
    std::cout << add (4.4, 5.6);
    return 0;
}