#include <iostream>

enum class Color {
    onyx,
    black,
    white,
    red,
    blue,
    green,
    yellow,
    pink,
    orange
};

enum class Balloon {
    red,
    blue,
    green,
    yellow
};

int main() {
    Color c { Color::red };
    Balloon b { Balloon::red };

    // if(Balloon::red == Color::red);  // ERROR: Can't be compared.
    // NOTE: Here, compiler doesn't implicitly convert enum types to ints.
    // Thus, Balloon & Color enum types are not comparable anymore as is 
    // the case with normal enum type.

    // std::cout << c;  // ERROR: std::cout can't print 'c'.
    // IMP: This is because, since compiler does not implicitly convert Color enum value to int - std::cout is unable to print c's value.

    std::cout << static_cast<int>(c);   // WORKS!

    return 0;
}