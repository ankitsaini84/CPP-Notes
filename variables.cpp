#include <iostream>

int main(void) {

    // Copy, Direct & List Initializations..
    int a = 1;  // NOTE: Copy Initialization of value 1 into 'a' variable - Much like copy assignment, it copies the value of 1 into 'a' variable.
    int b (2);  // NOTE: Direct initialization of value 2 into 'b' variable
    
    // TIP: For simple datatypes (like integers), copy and direct initializations are essentially the same.



    // List Initialization ~ also refferred to as uniform initialization or brace inintialization
    int c {3};  // NOTE: Direct initialization
    int d = {4};// NOTE: Copy initialization
    // TIP: Initializating a variable with empty braces indicates value initialization. 
    /*
     * IMP: This means that if you try to use list initialization to initialize 
     * a variable with a value it can not safely hold, the compiler will throw a warning or an error. 
     */
    int e {};    // Value Initialization - Intialize 'e' with 0
    

    /* 
     * int e{ 4.5 }; // ERROR: not all double values fit into an int
     * NOTE: In the above snippet, we’re trying to assign a number (4.5) that has a fractional part (the .5 part)
     * to an integer variable (which can only hold numbers without fractional parts). Copy and direct
     * initialization would drop the fractional part, resulting in initialization of value 4 into variable
     * width. However, with list initialization, this will cause the compiler to issue an error (which is
     * generally a good thing, because losing data is rarely desired). Conversions that can be done without
     * potential data loss are allowed.
     */

    /* TIP: Favor direct list initialization whenever possible. */
    /* TIP: Initialize your variables upon creation. */

    int f { e + 5}; // the compiler will resolve the expression to a single value and assign it to 'f'.
    // NOTE: Values calculated in an expression are discarded at the end of the expression.

    std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << "\nd = " << d << "\ne = " << e << "\nf = " << f << '\n';

    // IMP: Local variables always have a BLOCK SCOPE.
    // Which means they are in scope from their point of definition to the end of the block they are defined within.
    // IMP: Also, local variables have AUTOMATIC STORAGE DURATION.
    // Which means they are created at the point of definition and destroyed at the end of the block they are defined in.
    // EXAMPLE:
    int x { 3 };        // NOTE: X has a scope inside main() function's block.
    {                   // NOTE: NESTED BLOCK
        int y { 5 };    // NOTE: Y enters scope and is created here.
        // NOTE: An identifier’s LINKAGE determines whether other declarations of that name refer to the same object or not.
        // NOTE: Local variables have no LINKAGE, which means that each declaration refers to a unique object.
        int x { 6 };    // NOTE: This X is different object than previous X.
        
        std::cout << "Inner scope - " << x << " + " << y << " = " << x + y << '\n';
    }                   // NOTE: Y goes out of scope, and is destroyed here.
    // std::cout << x << " + " << y << " = " << x + y << '\n';  // ERROR: Y is not accessible here!

    // TIP: Define variables in the most limited existing scope.
    // TIP: Avoid creating new blocks whose only purpose is to limit the scope of variables.
    
    return 0;
}