#include <iostream>

int main() {
    float f1 = { 10 / 4};
    // Results in f1 = 2, as no promotion takes place. Integer Division is
    // performed on 10/4, resulting in value 2, which is implcitly 
    // converted to 2.0 & assigned to f1.
    
    float f2 = { 10 / 4.0 };
    // Results in f2 = 2.5, as one of the operands in double - Floating
    // Point Division is performed, resulting in value 2.5.
    
    int i1 { 10 };
    int i2 { 4 };
    float f3 = i1 / i2;
    // Results in f3 = 2, as we have no means of telling the compiler that
    // we want to use floarting point division, instaed or integer divison.

    // EXPLICIT TYPE CONVERSION
    // Types - 
    // #1. C-Style Cast (originates from standard C)
    // #2. Static Cast  (C++)
    // #3. Dynamic Cast (C++)
    // #4. Const Cast   (C++)
    // #5. ReInterpret Cast

    // C-Style Cast - It can perform static, const & reInterpret cast - 
    // depending upon the context. This is the reason - these are 
    // dangerous to use & should be avoided.

    float f4 { float(i1) / i2};
    // Above example shows a c-style in action. f4 will be assigned 2.5.

    // Static Cast - Used to convert a value of one type to another.
    float f5 { static_cast<float>(i1) / i2 };
    // Above example shows a static_cast in action.
    
    // TIP: Always favour static_cast, in place of C-Style casts, when one 
    // needs to convert a value from one type to another.
    
    return 0;
}