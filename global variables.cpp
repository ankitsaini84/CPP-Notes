#include <iostream>

int g_x { 5 };  // SCOPE - FILE Scope | Global Scope | Global Namespace Scope
int g_y;        // Defaultly initialized to 0

// NOTE: Global Variables are created when the program starts, & destroyed when the it ends.
// This is called STATIC DURATION.
// Variables w/ static duration are [sometimes] called STATIC VARIABLES.
// Unlike LOCAL variables, which are uninitialized by default, STATIC variables are zero-initialized by default.

// const int g_const;           // ERROR: Like all const variables, global const variables also have to be initialized.
// constexpr int g_constexpr;   // ERROR: Consexpr must always be initialized.




// NOTE: LINKAGE - Global variable and functions identifiers can have either INTERNAL LINKAGE or EXRERNAL LINKAGE.
// INTERNAL LINKAGE - Identifier can be seen and used within a single file, but is not accessible from other 
// files (i.e., it is not exposed to the linker)

// IMP: All const/constexpr global variables have INTERNAL LNKAGE, by default.
// IMP: All non-const global variables have EXTERNAL LINKAGE, by default.
// IMP: To make non-const global varibales have INTERNAL LINKAGE, we use static keyword.
// IMP: 'static' keyword is a STORAGE CLASS SPECIFIER - sets both linkage & storage duration (but not its scope).
int g_def;                      // Global variable with EXTERNAL linkage
const double g_pi = 3.14;       // Global const variable with INTERNAL linkage.
static int g_ext_linkage_var;   // Global static variable with INTERNAL linkage.
int main() {
    
    return 0;
}