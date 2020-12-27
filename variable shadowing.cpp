#include <iostream>

int main() {
    int x { 3 };                            // Outer block 'x'
    {                                       // Nested block
        std::cout << "X : " << x << '\n';   // Prints value of outer block scope

        // IMP: 'x' now refers to the nested block 'x' & outer block 'x' is temporarily HIDDEN.
        int x {};                           // Defines 'x' inside nested block
        std::cout << "X : " << x << '\n';   // Prints value of nested block scope

        x = 5;                              // Assigns '3' to nested block 'x'
        std::cout << "X : " << x << '\n';
    }                                       // Nested block destroyed

    std::cout << "X : " << x << '\n';       // Prints value of outer block scope

    return 0;
}