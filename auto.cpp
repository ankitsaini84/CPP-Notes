#include <iostream>

/*
auto add(auto a, auto b) {  // TIP: Do NOT return 'auto' type. Also, C++20 interoduces taking function arguments as 'auto'.
    return a + b;
}*/

int sum(const int a, const int b) {
    return a + b;
}

// TIP: Ideal use for 'auto' is when defining variables. e.g.
auto g_sum { sum(2, 3) };

int main() {
    std::cout << g_sum;
    return 0;
}