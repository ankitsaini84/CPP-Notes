#include <iostream>
#include <typeinfo>

// TYPE CONVERSION - converting a value from one datatype to another.

// NUMERIC PROMOTION - value from one fundamental datatype is converted into a value of a LARGER fundamental datatype from the SAME family.
long g_intToLong { 1 };             // Integral promotion - integer gets promoted to long type.
double g_floatToDouble { 1.2f };    // Floating point promotion - float gets promoted to double type.

// NUMERIC CONVERSIONS - convert a value from a larger type to a similar SMALLER type, or between DIFFERENT types.
float g_intToFloat { 10 };          // Convert int to float (between different type families)
double g_intToDouble { 2 };         // Convert int to double (between different type families)
short g_intToShort { 3 };           // Convert int to short (from larger to smaller within same type family)
float g_doubleToFloat { 5.987654 }; // Convert double to float (from larger to smaller within same type family)
// NOTE: Above examples may show precision loss due to inability of smaller datatypes of holding large values.
// char g_intToChar { 4000 };       // ERROR: Range Overflow - Undefined Behaviour
// int g_doubleToInt { 10.0 };      // ERROR: Range Overflow - Undefined Behaviour

int main() {
    std::cout << "g_intToLong :\t\t" << typeid(g_intToLong).name() << ' ' << g_intToLong << "\n";
    std::cout << "g_floatToDouble :\t" << typeid(g_floatToDouble).name() << ' ' << g_floatToDouble << "\n";
    std::cout << "g_intToFloat :\t\t" << typeid(g_intToFloat).name() << ' ' << g_intToFloat << "\n";
    std::cout << "g_intToDouble :\t\t" << typeid(g_intToDouble).name() << ' ' << g_intToDouble << "\n";
    std::cout << "g_intToShort :\t\t" << typeid(g_intToShort).name() << ' ' << g_intToShort << "\n";
    std::cout << "g_doubleToFloat :\t" << typeid(g_doubleToFloat).name() << ' ' << g_doubleToFloat << "\n";

    // NOTE: Evaluating arithmetic expressions - 
    // When evaluating expressions, the compiler breaks each expression down into individual subexpressions.
    // The arithmetic operators require their operands to be of the same type.
    // To ensure this, the compiler uses the following rules - 
    // #1. If an operand is an integer that is narrower than an int, it undergoes integral promotion to int or unsigned int.
    // #2. If the operands still don't match, then compiler finds the highest priority operand & implicitly converts other operand to match.
    // Priority of Operands is as follows -
    // long double (highest)
    // double
    // float
    // unsigned long long
    // long long
    // unsigned long
    // long
    // unsigned int
    // int (lowest)
    
    // EXAMPLES:
    short a{ 4 };
    short b{ 5 };
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n';  // Shorts ungergo Integral Promotion
    double d{ 4.0 };
    short s{ 2 };
    std::cout << typeid(d + s).name() << ' ' << d + s << '\n';
    // NOTE: Short integral ungergo Integral Promotion.  However, the int and double still do not match. Since double is higher on the hierarchy of types, the integer 2 gets converted to the double 2.0, and the doubles are added to produce a double result.

    return 0;
}