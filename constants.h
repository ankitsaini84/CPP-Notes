#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {   // User-defined namespace
    constexpr double pi { 3.14 };               // TIP: Avoid! C++11/14
    // TIP: Avoid this, if using C++ version 17 or above. Always prefer to make such variables inline (C++17).
    // Downside of using this approach -
    // All these variables will be copied in the .cpp file when included. So, if the file is copied 10 times - 
    // our program will require 10 times as much memory for storing these variables.

    // IMP: INLINE VARIABLES (introduced in C++ 17) - Multiple definitions are allowed.
    // IMP: Inline global variables have external linkage by default.
    
    // NOTE: The linker will consolidate all inline definitions into a single variable definition. 
    // This allows us to define variables in a header file and have them treated as if there was only 
    // one definition in a .cpp file somewhere. 
    // These variables also retain their constexpr-ness in all files in which they are included.
    inline constexpr double gravity { 9.8 };    // TIP: Best Practice
}
#endif