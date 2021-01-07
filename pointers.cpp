#include <iostream>
#include <typeinfo>     // typeid()
#include <cstddef>      // NULL // TIP: Avoid Using NULL

// TIP: When declaring a function, put the asterisk of a pointer return 
// value next to the type.
int* foo1(int arr[]) {
    return nullptr;
}   // IMP: Compiler implicitly converts (decays) arr[] to int*

int foo2(int *arr) {    // TIP: Better Practice than previous notation.
    *arr = 1;
    return 0;
}   // IMP: Compiler implicitly converts (decays) *arr to int*

int main() {
    int x { 5 };
    std::cout << "x : "     << x       << '\n';
    std::cout << "&x : "    << &x      << '\n'; // Address-of operator [&] 
    std::cout << "*(&x) : " << *(&x)   << '\n'; // Indirection/defrencing [*]

    int *iPtr { &x };
    // TIP: When declaring a pointer variable, put the asterisk next to 
    // the variable name.
    // Indirection through pointers
    // NOTE: Indirection through a pointer evaluates to the contents of the 
    // address it is pointing to. This is why pointers should have type.
    // IMP: Without type, compiler wouldn't know how to interpret the 
    // contents it is pointing to.
    std::cout << "iPtr : "  << iPtr    << '\n';
    std::cout << "*iPtr : " << *iPtr   << '\n';

    // Invalid Assginments
    // double *dPtr { iPtr };   // ERROR: int* != double*
    // int *iPtr2 { x };        // ERROR: int* != int
    
    // IMP: Address-of operator returns a pointer.
    std::cout << "Address-of operator type : " << typeid(&x).name() << '\n';

    

    // IMP: Size of the pointers.
    // Size of the pointers is always the same, regardless what they are pointing to.
    // On 32-bit machines - size of the pointer is 32 bits - 4 bytes.
    // On 64-bit machines - size of the pointer is 64 bits - 8 bytes.
    std::cout << "sizeof(iPtr) : " << sizeof(iPtr) << " bytes\n";
    double *dPtr { nullptr };       // TIP: Best practice
    std::cout << "sizeof(dPtr) : " << sizeof(dPtr) << " bytes\n";
    int *iPtr3 { NULL };            // Another practice - Best use nullptr
    int *iPtr4 { 0 };               // TIP: ALWAYS AVOID!



    // ARRAY DECAY
    constexpr int MAX { 5 };
    int array[MAX] { 9, 8, 7, 6, 5 };
    std::cout << "&array[0] : " << &array[0] << '\n';
    std::cout << "array : "     << array << '\n';

    std::cout << "*array : "    << *array << '\n';
    std::cout << "array[0] : "  << array[0] << '\n';
    iPtr = array;
    std::cout << "*iPtr : "     << *iPtr << '\n';
    foo2(array);    // IMP: Call by Address - 'array' will decay to 'int*'
    std::cout << "array[0] : "  << array[0] << '\n';
    /**
     * IMP: It's a common fallacy to belive that an array & a pointer are 
     * identical. They are not!
     * Above, array is of type 'int[5]', & its value is the array element 
     * themselves.
     * A pointer to the array would be of type 'int*', & its value would be
     * the address of the first element of the array.
     * This works, because the array decays into a pointer of type int*, & 
     * our pointer also has the same type (i.e. int*).
     */
    // To prove these 2 are different.. print their respective sizes.
    std::cout << "sizeof(array) : " << sizeof(array) << '\n';
    // Statement above, prints the size of the array as 20.
    std::cout << "sizeof(iPtr) : "  << sizeof(iPtr) << '\n';
    // Statement above, prints the size of the pointer as 8.



    // POINTER ARITHMETIC
    // NOTE: pointer + 1 returns the memory address of the next object of 
    // the type that pointer points to.
    // Example : 
    const int length = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < length; ++i) {
        std::cout << "iPtr + " << i << " : " << iPtr + i
        << " : " << *(iPtr + i) << '\n';
    }
    // Above, each iteration prints the address of subsequent elements in 
    // the array as the iPtr points to int (4 bytes) and +1 makes it point 
    // to the next element in the array.



    /**
     * VOID POINTERS (Generic Pointers)
     * Void pointers can point to objects of any data type.
     * And however, it doesn't know what type of object it is pointing to, it needs to be
     * explicitly casted to another pointer type before indirection.
     */

    void *voidPtr {nullptr};
    int value {5};

    voidPtr = &value;

    // std::cout << "Value @ voidPtr : " << *voidPtr;   //ERROR: Illegal indirection
    std::cout << "Value @ voidPtr : " << *(static_cast<int*>(voidPtr)) << '\n'; // Works!

    // TIP: Some compilers allow to DELETEING a void pointer pointing to dynamically allocated
    // memory. Doing so should be avoided, as it can result in undefined behaviour.

    // NOTE: Also, doing POINTER ARTITHMATIC, is not possible on a void pointer as it doens't know the type (or size) of the object it is pointing to.

    // NOTE: Also, there's no such thing as a VOID REFERENCE as it would have to point to an 
    // object of type void and it's have no way of knowing what type of value it referenced.
    
    // TIP: Avoid using void pointers unless neccessary.




    // POINTER TO POINTER
    // A 'pointer to a pointer' is a pointer that holds the address of another pointer.
    int *iPtr5 { &value };  // int-poiner holds address of int
    int **pPtr1 { &iPtr5 }; // int-pointer-to-pointer holds address of int-pointer
    // int **pPtr2 { &&value };
    // ERROR: A pointer-to-pointer can't be directly assigned a value
    // IMP: Since, 'operator&' requires an lvalue, but '&value' is an rvalue.

    // pointer-to-pointer Extravagenza..
    int *arr[MAX];                  // Allocating an Array of Pointers
    int **arrPtrs { new int*[MAX]}; // Dynamically allocating an array of pointers
    delete[](arrPtrs);              // Deallocating memory for array of pointers

    int arr2D1[MAX][MAX];           // Allocating a 2-D array
    // int **arr2D2 = new int[MAX][MAX];    // ERROR: Invalid
    int (*arr2D3)[MAX] = new int[MAX][MAX]; // Only works if MAX is a compile-time constant
    auto arr2D4 = new int[MAX][MAX];        // Same as above but neat ~ C++11

    int **arr2D5 = new int*[MAX];   // Dynamically allocating a 2-D array
    for (int i = 0; i < MAX; ++i) {
        arr2D5[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; ++i) { // Deallocating memory alloted to 2-D array
        delete[](arr2D5[i]);
    }
    delete[](arr2D5);

    // TIP: Avoid pointer-to-pointer unless very neccessary.

    return 0;
}