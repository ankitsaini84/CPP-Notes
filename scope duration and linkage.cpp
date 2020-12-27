#include <iostream>       
///////////////////////////////////////////////////////////////////////////////
// File scope:
       int g_var{ 4 };              // external non-constant global variable
static int g_internalVar{ 5 };      // internal non-constant global variable
 
              const int g_constVar{ 6 };         // internal        constant global variable
extern        const int g_externalConstVar{ 7 }; // external        constant global variable
extern inline const int g_inlineConstVar{ 8 };   // external inline constant global variable
 
              constexpr int g_constexprVar{ 9 };        // internal        constant global variable
extern        constexpr int g_externConstexprVar{ 10 }; // external        constant global variable
extern inline constexpr int g_inlineConstexprVar{ 11 }; // external inline constant global variable
///////////////////////////////////////////////////////////////////////////////
 
void functionOne(int functionParameter) // function parameter
{
    std::cout << functionParameter;
}
 
#include "scope duration and linkage.h"
#include <iostream>
 
int main()
{
    // Block scope:
           int localVar{ 1 };   //        local variable
    static int s_localVar{ 2 }; // static local variable
 
    int* dynamicVar{ new int{ 3 } }; // dynamic variable
 
    std::cout << localVar << '\n';             // 1
    std::cout << s_localVar << '\n';           // 2
    std::cout << dynamicVar << '\n';           // 3 (output looks weird, I haven't learned about pointers yet)
    std::cout << g_var << '\n';                // 4
//  std::cout << g_internalVar << '\n';        // Not forward declared because internal
//  std::cout << g_constVar << '\n';           // Not forward declared because internal
    std::cout << g_externalConstVar << '\n';   // 7
    std::cout << g_inlineConstVar << '\n';     // 8
//  std::cout << g_constexprVar << '\n';       // Not forward declared because constexpr
//  std::cout << g_externConstexprVar << '\n'; // Not forward declared because constexpr
//  std::cout << g_inlineConstexprVar << '\n'; // Not forward declared because constexpr
 
    return 0;
}