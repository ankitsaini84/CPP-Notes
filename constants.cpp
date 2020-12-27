#include "constants.h"
#include <iostream>

int main () {

    // COMPILE TIME CONSTANTS
    // NOTE: Following are the compile time constants, as their values can be resolved by compiler during compilation.
    // NOTE: To make a variable constant, simply put the const keyword either before or after the variable type
    const double pi {3.14};        // TIP: Always Recommended
    double const g {9.8};

    // const double gravity;    // NOTE: Compiler Error - Must be initialized upon definition.


    // RUNTIME CONSTANTS
    int x {};
    std::cout << "Provide value for x : ";
    std::cin >> x;
    const int y {x};            // NOTE: Y is a run-time constant, as it's value can only be resolved at runtime.

    // CONSTEXPR
    // IMP: Constexpr ensures that a constant must be a compile-time constant.
    constexpr double gravity { 9.8 };   // VALID - Can be resolved at compile time.
    constexpr int sum { 2 + 3 };        // VALID - Can be resolved at compile time.
    
    int a {};
    std::cout << "Provide value for a : ";
    std::cin >> a;
    // constexpr int b {a};                // ERROR: Can't be resolved at compile time.

    // TIP: Any constant variable whose initializer is known at compile-time should be declared as CONSTEXPR.
    // TIP: Any constant variable whose initializer is not known at compile-time should be declared as CONST.

    // TIP: C++14 Practice -
    // Declare constexpr varibales in seperate headerfile inside a namespace
    // ------- Refer constants.h for declaration --------
    std::cout << "Value of Pi : " << constants::pi << '\n';

    // NOTE: In C++17, constexpr can be declared as inline.
    // TIP: Best Practice - Refer 'constants.h' for explaination.
    std::cout << "Value of Gravity : " << constants::gravity << '\n';

    return 0;
}