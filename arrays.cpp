#include <iostream>
#include <iterator> // std::size() - c++17

void printLength(int arr[]) {
    // int length { std::size(arr) }; // ERROR: Won't work for int*.

    // NOTE: Arrays are passed as pointers and no actual copy of them are
    // being made here. This is to do with the fact that arrays are not 
    // handled in the same way as normal-variables in C++.
    // So, std::size() is incapable of fiding length of arrays
    // being passed as arguments.
}

int main() {
    constexpr int MAX = 5;

    // Ways to initialize [fixed] arrays

    // Using initializer's list..
    // #1. All elements are initialized w/ their respective values.
    int primes[MAX] {2, 3, 5, 7, 11};
    
    // #2. Remaining elements are initialized by '0'.
    int array1[MAX] {1, 2, 3}; // 1, 2, 3, 0, 0

    // #3. All elements are initialized by '0', '0.0' & "", respectively.
    int array2[MAX] { };
    double array3[MAX] { };
    std::string array4[MAX] { };

    // #4. All elements are un-initlialized, except for class-types.
    int array5[MAX];        // All Garbage values
    double array6[MAX];     // All Garbage values
    std::string array[MAX]; // IMP: Initlaized to "" (Empty Strings).

    // TIP: Always initialize arrays.




    // Determine length of the array
    int length { std::size(primes) };
    std::cout << "Length of the array (primes) : " << length << '\n';

    // NOTE: Another way of finding array length
    length = sizeof(primes) / sizeof(primes[0]);
    std::cout << "Length of the array (primes) : " << length << '\n';




    // Passing array as call-by-value argument
    printLength(primes);

    return 0;
}