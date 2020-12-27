#include <iostream>

int g_x { 5 };  // SCOPE - FILE Scope | Global Scope | Global Namespace Scope
int g_y;        // Defaultly initialized to 0

// NOTE: Global Variables are created when the program starts, & destroyed when the it ends.
// This is called STATIC DURATION.
// Variables w/ static duration are [sometimes] called STATIC VARIABLES.
// Unlike LOCAL variables, which are uninitialized by default, STATIC variables are zero-initialized by default.

// const int g_const;           // ERROR: Like all const variables, global const variables also have to be initialized.
// constexpr int g_constexpr;   // ERROR:

int main() {
    
    return 0;
}