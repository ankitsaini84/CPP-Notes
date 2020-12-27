#include <iostream>

int main(void) {

    // COPY, DIRECT & LIST Initializations..
    int a = 1;  // COPY Initialization of value 1 into 'a' variable - Much like copy assignment.
    int b (2);  // DIRECT initialization of value 2 into 'b' variable
    // TIP: For simple datatypes (like integers), COPY and DIRECT initializations are essentially the same.

    // LIST Initialization - also refferred to as UNIFORM initialization or BRACE inintialization
    int c {3};  // DIRECT initialization
    int d = {4};// COPY initialization

    // VALUE Initialization - Initializating a variable with empty braces. 
    int e {};    // VALUE Initialization - Intialize 'e' with 0
    
    // int e { 4.5 }; // ERROR: not all double values fit into an int
    // IMP: This means that if you try to use LIST initialization to initialize a variable with a value it 
    // can not safely hold, the compiler will throw a warning or an error. 
    /* 
     * NOTE: In the above snippet, we’re trying to assign a number (4.5) that has a fractional part (the .5 part)
     * to an integer variable (which can only hold numbers without fractional parts). Copy and direct
     * initialization would drop the fractional part, resulting in initialization of value 4 into variable
     * width. However, with LIST initialization, this will cause the compiler to issue an error (which is
     * generally a good thing, because losing data is rarely desired). Conversions that can be done without
     * potential data loss are allowed.
     */

    // TIP: Favor DIRECT LIST initialization whenever possible.
    // TIP: Initialize your variables upon creation.

    int f { e + 5}; // the compiler will resolve the expression to a single value and assign it to 'f'.
    // NOTE: Values calculated in an expression are discarded at the end of the expression.

    std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << "\nd = " << d << "\ne = " << e << "\nf = " << f << '\n';

    // NOTE: Local variables always have a BLOCK SCOPE.
    // Which means they are in scope from their point of definition to the end of the block they are defined within.
    // NOTE: Local variables have AUTOMATIC STORAGE DURATION.
    // Which means they are created at the point of definition and destroyed at the end of the block they are defined in.
    // NOTE: An identifier’s LINKAGE determines whether other declarations of that name refer to the same object or not.
    // NOTE: Local variables have no LINKAGE, which means that each declaration refers to a unique object.
    // EXAMPLE:
    int x { 3 };        // X has a scope inside main() function's block.
    {                   // NESTED BLOCK
        int y { 5 };    // Y enters scope and is created here.
        int x { 6 };    // Linkage - This 'x' is different object than previous 'x'.
        
        std::cout << "Inner scope - " << x << " + " << y << " = " << x + y << '\n';
    }                   // Y goes out of scope, and is destroyed here.
    // std::cout << x << " + " << y << " = " << x + y << '\n';  // ERROR: Scope - Y is not accessible here!

    // TIP: Define variables in the most limited existing scope.
    // TIP: Avoid creating new blocks whose only purpose is to limit the scope of variables.
    
    return 0;
}