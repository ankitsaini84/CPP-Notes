/**
 * NOTE: Types of Memory Allocations:
 * 
 * STATIC MEMORY ALLOCATION: 
 * For Static & Global variables. 
 * Allocated once - when your program is run.
 * Perists throughout the life of the program.
 * 
 * 
 * AUTMOMATIC MEMORY ALLOCATION:
 * For function parameters & local variables.
 * Allocated when relevant block is entered, & freed when when 
 * the block is exited.
 * 
 * DYNAMIC MEMORY ALLOCATION:
 * Since, a program has a limited pool of STACK memory 
 * (usually 1 ~ 2 MB), we ask OS for more memory from its 
 * reserve (usually in GBs) called HEAP memory.
 */

#include <iostream>

int main() {
    constexpr int MAX { 5 };
    int *ptr1 { new int (MAX) }; // DIRECT INITIALIZATION
    int *ptr2 { new int {MAX} }; // INDIRECT INITIALIZATION

    /**
     * IMP: By default, new() throws 'std::bad_alloc' 
     * exception, if OS is unable to provide memory. If 
     * unhandled, program will crash with unhandled exception.
     */
    // Alternate form of new() - 
    int *ptr3 = new (std::nothrow) int;
    // IMP: Value of 'ptr3' will be set to nullptr if new fails.
    if(!ptr3) {
        std::cout << "new() failed to allocate memory!\n";
        return 0;
    }

    delete ptr1;    // return memory pointed by ptr1 to OS
    ptr1 = nullptr; // set ptr1 to be a null pointer
    
    /** 
     * NOTE: C++ does NOT gaurantee about what will happen to 
     * the contents of deallocated mamory, or the value of the 
     * pointer being deleted.
     * In most cases, memory returned to OS will conatin same 
     * values it had before it was returned, & pointer will be 
     * left pointing to the now new deallocated memory.
     * Such a pointer is called DANGLING POINTER.
     */
    *ptr2 = 5;
    delete ptr2;
    // NOTE: ptr2 has been deleted but not been assigned nullptr
    // ptr2 is a dangling pointer now.
    std::cout << "Dangling pointer value : " << *ptr2 << '\n';

    // TIP: To handle this issue - Always assign nullptr to 
    // pointer after deletion.
    ptr2 = nullptr;

    // if(ptr3 != nullptr) {
    // IMP: Deleting a nullptr has no effect, we can ommit null 
    // check before deleting a pointer.
        delete ptr3;
        ptr3 = nullptr;
    // }



    // Dynamically Allocating Arrays
    constexpr std::size_t LEN { 5 };
    int *array { new int [LEN] };   // new[] operator is called!
    // Delete dynamically allocated array'
    delete[] array;                 // delete[] is called.!
    // delete array;                // ERROR: Undefined behavior

    // Initializing dynamic arrays
    int *arr1 { new int [LEN] {} }; // Init by 0s
    // Via initl=ializer's list
    int *arr2 { new int [LEN] { 1, 2, 3, 4, 5 } };
    // use 'auto' to prevent writing 'int' twice!
    auto *arr3 { new int [LEN] { 1, 2 } };
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    // MEMORY LEAKS
    int value { 5 };
    int *ptr4 { new int {}};// Allocate memory
    // ptr4 = &value;       // Old address lost. Memory leaks.
    // Fix: delete ptr4 b4 assigning it new value, as following
    delete ptr4;
    ptr4 = &value;

    // Reallocating memory without deleting old, also creates 
    // memory leak as the address returned by 2nd allocation 
    // overwrites the address of previous allocation.
    // Example ~
    // int *ptr4 { new int{} };
    // ptr4 = new int {};

    return 0;
}