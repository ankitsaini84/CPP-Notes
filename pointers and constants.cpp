#include <iostream>

int main() {
    const int value1 { 3 };
    int value2 { 3 };

    int *ptr0 { &value2 };
    std::cout << "Values before change..\n";
    std::cout << "*ptr0 : " << *ptr0 << '\n';
    std::cout << "value2 : " << value2 << '\n';
    *ptr0 = 5;                  // Allowed to change the value of value2
    std::cout << "Values after change..\n";
    std::cout << "*ptr0 : " << *ptr0 << '\n';
    std::cout << "value2 : " << value2 << '\n';


    // int *ptr1 { &value1 };   // ERROR: Can not initlialize int* with const int*
    // NOTE: If this was allowed, it'd mean that we are allowed to change the
    // value of 'const int' via pointer.
    // Somthing like this - 
    // *ptr1 = 5;

    // POINTER TO CONST VALUE
    // So, what works is - 
    const int *ptr2 { &value1 };// IMP: 'Pointer to a const value'
    // NOTE: Here, pointer points to a const value
    // *ptr2 = 5;               // ERROR: Not allowed to change a const value
    
    const int *ptr3 { &value2 };
    std::cout << "\nValues before change..\n";
    std::cout << "*ptr3 : " << *ptr3 << '\n';
    std::cout << "value2 : " << value2 << '\n';
    // NOTE: 'pointer to a const value' treats the variable as const when 
    // accessed via pointer. Thus, following is not allowed.
    // *ptr3 = 2;               // ERROR: Variable is const when accessed via ptr
    // NOTE: But, following is allowed.
    value2 = 2;                 // variable in itself is not 'const'
    std::cout << "Values after change..\n";
    std::cout << "*ptr3 : " << *ptr3 << '\n';
    std::cout << "value2 : " << value2 << '\n';



    // CONST POINTER
    int *const ptr4 { &value2 };// IMP: 'Const Pointer'
    std::cout << "\nValues before change..\n";
    std::cout << "*ptr4 : " << *ptr4 << '\n';
    std::cout << "value2 : " << value2 << '\n';
    // NOTE: It'll always point to same address. Thus, it's allowed to change the 
    // value of the varible but not allowed to change the address pointer is pointing to
    value2 = 3;                 // Allowed, since, value2 is not constant
    std::cout << "Values after change..\n";
    std::cout << "*ptr4 : " << *ptr4 << '\n';
    std::cout << "value2 : " << value2 << '\n';
    // ptr4 = &value1;          // ERROR: Not allowed to change the address of the pointer


    // CONST POINTER TO CONST VALUE
    const int *const ptr5 { &value2 };
    std::cout << "\nValues before change..\n";
    std::cout << "*ptr5 : " << *ptr5 << '\n';
    std::cout << "value2 : " << value2 << '\n';
    // IMP: Neither pointer's address can be changed, nor the value it's pointing to
    // ptr5 = &value1;          // ERROR: Not allowed to change the address of the pointer
    // *ptr5 = 0;               // ERROR: Value is const when accessed via pointer
    value2 = 0;                 // Allowed, since value2 is not constant
    std::cout << "Values after change..\n";
    std::cout << "*ptr5 : " << *ptr5 << '\n';
    std::cout << "value2 : " << value2 << '\n';


    // TIP: To Remember - Type of the value the pointer points to is always on the left of '*'
    // Examples - 
    const int *ptr6 = &value2;          // Pointer points to 'const int'
    int *const ptr7 = &value2;          // Const-Pointer points to an 'int'
    const int *const ptr8 = &value2;    // Const-Pointer points to 'const int'
    
    return 0;
}