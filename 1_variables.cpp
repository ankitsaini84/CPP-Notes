#include <iostream>

using namespace std;

int main(void) {
    // Copy, Direct & List Initializations..

    int a = 1;  // Copy Initialization of value 1 into 'a' variable - Much like copy assignment, it copies the value of 1 into 'a' variable.
    int b (2);   // Direct initialization of value 2 into 'b' variable
    /* TIP - For simple datatypes (like integers), copy and direct initializations are essentially the same. */

    // List Initialization ~ also refferred to as uniform initialization or brace inintialization
    int c {3};  // ~ Direct initialization
    int d = {4};// ~ Copy initialization

    /*
     * Initializating a variable with empty braces indicates value initialization. 
     * IMPORTANT :- This means that if you try to use list initialization to initialize 
     * a variable with a value it can not safely hold, the compiler will throw a warning or an error. 
     */
    int e {};    // Value Initialization - Intialize 'e' with 0
    
    /* 
     * int e{ 4.5 }; // error: not all double values fit into an int
     * In the above snippet, we’re trying to assign a number (4.5) that has a fractional part (the .5 part)
     * to an integer variable (which can only hold numbers without fractional parts). Copy and direct
     * initialization would drop the fractional part, resulting in initialization of value 4 into variable
     * width. However, with list initialization, this will cause the compiler to issue an error (which is
     * generally a good thing, because losing data is rarely desired). Conversions that can be done without
     * potential data loss are allowed.
     */

    /* TIP :- Favor direct list initialization whenever possible. */
    /* TIP :- Initialize your variables upon creation. */

    cout << "a = " << a << "\nb = " << b << "\nc = " << c << "\nd = " << d << "\ne = " << e << "\n";
    return 0;
}