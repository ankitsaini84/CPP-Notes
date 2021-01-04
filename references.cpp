// NOTE: Reference is a type of variable that acts as an ALIAS to another object or value
#include <iostream>     // std::cout
#include <iterator>     // std::size()

void addOne(int &ref) { // Sets 'ref' as reference to the passed argument
    ++ref;              // Modifies passed argument (via reference)
}

void print(int (&arr)[5]) { // IMP: Need to define array size in func. decalaration
    // NOTE: Since, array didn't decay, std:size() will return length of array rather than 
    // size of int*.
    int length {static_cast<int>(std::size(arr))};
    std::cout << "Printing array..\n";
    for(int i = 0; i < length; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    // references act identically to the values they're referencing
    int x{5};
    int &ref1{x};       // reference to 'x'
    int &ref2{ref1};    // reference to 'x'

    std::cout << "Value of x : " << x << '\n';              // prints 5
    std::cout << "Value of ref1 : " << ref1 << '\n';        // prints 5
    std::cout << "Value of ref2 : " << ref2 << '\n';        // prints 5

    ++ref2;
    std::cout << "Value of 'x : " << x << '\n';             // prints 6

    std::cout << "Addrerss of x : " << &x << '\n';
    std::cout << "Addrerss of ref1 : " << &ref1 << '\n';    // prints same addr as &x
    std::cout << "Addrerss of ref2 : " << &ref2 << '\n';    // prints same addr as &x

    // IMP: References can't be re-assigned.
    int y{3};
    ref2 = y;           // NOTE: Doesn't reassign reference. Assigns y's value to 'x'
    std::cout << "Value of x : " << x << '\n';              // prints 3
    std::cout << "Value of ref2 : " << ref2 << '\n';        // prints 3
    std::cout << "Addrerss of ref2 : " << &ref2 << '\n';    // prints same addr as &x


    // IMP:NOTE: References must always be initialized.
    // int &ref3;       // ERROR: Un-inititalized reference

    const int z{3};
    // int &ref4{z};    // ERROR: Non-const reference can't refer const variables
    // int &ref5{5};    // ERROR: Non-const reference can't refer const literals
    
    // NOTE: Function using reference as parameter is able to modify value of passed argument
    std::cout << "Value of y : " << y << '\n';              // prints 3
    addOne(y);
    std::cout << "Value of y : " << y << '\n';              // prints 4

    // TIP: Pass arguments as non-const reference (rather than by pointer) when the argument
    // needs to be passed by the function.

    // IMP: When [c-style] arrays are passed as reference, they don't decay.
    int array[] = {1, 2, 3, 4, 5};
    print(array);   // 'array' won't decay to 'int*'
    


    // REFERENCES vs. POINTERS
    // NOTE: References act like a pointer thatr implicitly performs indirection through it 
    // when accessed.
    int *const ptr {&x};
    int &ref6 {x};
    std::cout << "Value of *ptr : " << *ptr << '\n';        // prints 3
    std::cout << "Value of ref6 : " << ref6 << '\n';        // prints 3



    // REFERENCE TO CONST VALUE
    // A reference to const value is called 'const reference'
    const int &cref1{y};    // reference to a const value
    // ++cref1;             // ERROR: Not allowed as cref1 is alias to const 'y'
    const int &cref2{x};    // Const refences can also point to non-const values.
    // ++cref2;             // ERROR: Not allowed to change 'x' via const reference.
    ++x;                    // Obviously, it's allowed.
    const int &cref3{3};    // Valid, as '3' is a const literal.


    /**
     * TIP: To avoid making unneccessary, potentially expensive copies, variables that are 
     * not pointers or fundamental data types shoulld be generally be passed by (const) 
     * reference.
     * Fundamental datatypes should be passed by value, unaless the function needs to change 
     * them.
     */

    return 0;
}



