// NOTE: This file is only being used as helping file 'external linkage.cpp'
// To refer EXTERNAL LINKAGE - visit 'external linkage.cpp'
// To refer INTERNAL LINKAGE - visit 'global variables.cpp' & 'functions.cpp'

#include <iostream>

// IMP: Since, the functions are externally linked by default, we can access this function
// anywhere outside this file (such as being used in 'external linkage.cpp').
// If functions had internal linkage - we wouldn't have been able to access it outsite this file, by default.
int getX() {
    int x {};
    std::cout << "Provide value for X : ";
    std::cin >> x;
    return x;
}

extern int g_a { 0 };           // ERROR: 'extern' keyword will be ignored, as all non-const global variables are extern by default.
extern const int g_y { 2 };     // IMP: 'extern' - give this variable external linkage.