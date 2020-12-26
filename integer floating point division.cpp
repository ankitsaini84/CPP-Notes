#include <iostream>

int main() {
    int a { 5 };
    int b { 3 };
    double c { 2.5 };
    double d { 2.0 };

    // NOTE: If both of the operands are integers, the division operator performs INTEGER POINT DIVISION. 
    std::cout << "int[5] / int[3] : " << a / b << '\n'; // INTEGER POINT DIVISION drops any fractions and returns an integer value.

    // NOTE: If either (or both) of the operands are floating point values, the division operator performs FLOATING POINT DIVISION. 
    std::cout << "int[5] / double[2.0] : " << a / d << '\n'; // FLOATING POINT DIVISION returns a floating point value, and the fraction is kept.
    std::cout << "int[5] / double[2.5] : " << a / c << '\n'; // FLOATING POINT DIVISION returns an integer value.

    // How to divide 2 integers without losing the fraction ?
    // TIP: Use static_cast
    std::cout << "double[5] / double[3] : " << static_cast<double>(a) / static_cast<double>(b) << '\n';
    
    return 0;
}