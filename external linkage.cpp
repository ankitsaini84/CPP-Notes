// NOTE: For INTERNAL linkage references - visit 'global variables.cpp' & 'functions.cpp'.
// TIP: Compile as - "g++ '.\external linkage.cpp' '.\linkage.cpp' -o '.\_output\external_linkage.exe'"

#include "linkage.h"
#include <iostream>

// NOTE: EXTERNAL LINKAGE - 
// An identifier with external linkage can be seen and used both from the file in which 
// it is defined, and from other code files (via a forward declaration). In this sense, 
// identifiers with external linkage are truly “global” in that they can be used anywhere in your program!

// IMP: All functions have EXTERNAL linkage, by default.
// In order to call a function in another file, one must place a FORWARD DECLARATION for the function
// in any other files wishing to use the function.
// It tells the compiler about the existence of the function, and the linker connects the function calls to the 
// actual function definintion.




// EXTERNAL VARIABLES - Global variables with external linkage.
int g_x { 1 };              // IMP: Non-const global variables are external by default

// NOTE: Use 'extern' keyword to make global variables EXTERNAL.
// How to use external global variable, that has been defined in another file ?
// Similar to external functions usage - forward decalre global variable.
// FORWARD DECLARATIONS - Refer file linkage.h.

// TIP: If you want to define an uninitialized non-const global variable, do not use the extern keyword, 
// otherwise compiler will think you’re trying to make a forward declaration for the variable.
extern int g_b;

// TIP: Although constexpr variables can be given external linkage via the extern keyword, 
// they can not be forward declared, so there is no value in giving them external linkage.
constexpr int g_z { 3 };

int main() {
    int x { getX() };   // Forward declaration can be found in 'linkage.h'
    std::cout << "Value of x : " << x << '\n';
    std::cout << "Value of g_a : " << g_a << '\n';
    // std::cout << "Value of g_b : " << g_b << '\n';   // ERROR: 'g_b' has no definition - only forward declaration w/ keyword 'extern'
    std::cout << "Value of g_x : " << g_x << '\n';
    std::cout << "Value of g_y : " << g_y << '\n';
    std::cout << "Value of g_z : " << g_z << '\n';
    return 0;
}
