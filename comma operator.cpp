#include <iostream>

// NOTE: A comma-operator allows you to evaluate multiple expressions wherever a single expression is allowed. 
// The comma operator evaluates the left operand, then the right operand, and then returns the result of the right operand.

int main() {
    int a { 1 };
    int b { 2 };
    int c, d;

    std::cout << "(++a, ++b) : " << (++a, ++b) << '\n';

    // NOTE: Comma has the lowest precedence of all the operators, even lower than assignment. 
    // Because of this, the following two lines of code do different things
    c = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable c.
    d = a, b;   // evaluates as "(d = a), b", so d gets assigned the value of a, & b is evaluated & discarded.
    std::cout << "(a, b) : " << c << '\n';
    std::cout << "a, b : " << d << '\n';

    return 0;
}