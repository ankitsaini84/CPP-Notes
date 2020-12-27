#include <iostream>

int x { 84 };                               // 'x' in GLOBAL SCOPE

int main() {
    // NOTE: Local variables with the same name as a global variable will shadow the global variable wherever the local variable is in scope.
    int x { 30 };                           // MAIN block 'x' - It shadows 'x' in GLOBAL scope
    {                                       // NESTED block
        std::cout << "X : " << x << '\n';   // Prints value of MAIN block scope

        // IMP: 'x' now refers to the NESTED block 'x' & MAIN block 'x' is temporarily HIDDEN.
        int x {};                           // NESTED block 'x' - It shadows 'x' in MAIN scope
        std::cout << "X : " << x << '\n';   // Prints value of NESTED block scope

        x = 5;                              // Assigns '3' to NESTED block 'x'
        std::cout << "X : " << x << '\n';
    }                                       // NESTED block destroyed

    std::cout << "X : " << x << '\n';       // Prints value of 'x' in MAIN block scope
    std::cout << "X : " << ::x << '\n';     // Prints value of 'x' in GLOBAL scope

    return 0;
}