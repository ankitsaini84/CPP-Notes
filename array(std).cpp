/**
 * Downsides of Fixed Arrays & Dynamic Arrays..
 * Fixed Arrays decay, & when they do, they lose the array length information.
 * Dynamic Arrays are messy to implement & re-size.
 * 
 * std::array overcomes these downsides as they don't decay & are easy to implement.
 * Syntax:
 * std::array<datatype, size> array_name;
 */

#include <iostream>     // std::cout
#include <array>        // std::array
#include <algorithm>    // std::sort

constexpr int MAX {5};

// size_t getLength(const std::array &a) {      // ERROR: Doesn't work. TODO: Why?
size_t getLength(const std::array<int, MAX> &a) {
    // TIP: Always pass std::array by reference or const reference.
    return a.size();
}

int main() {
    std::array<int, MAX> arr1;                  // Declaration
    std::array<int, MAX> arr2 {1, 2, 3, 4, 5};  // List Initialization
    std::array<int, MAX> arr3 = {5, 4, 3, 2, 1};// Initialization via Intializer list
    
    // std::array<int> arr5 {1, 2, 3, 4, 5};    // ERROR: Not allowed to omit array size
    // std::array<int, > arr4 {1, 2, 3, 4, 5};  // ERROR: Not allowed to omit array size
    // NOTE: Although, this restriction is removed in C++20 by using 'std::to_array'.
    
    // Although, only array size alone can't be omitted from std::array's declaration,
    // but (since c++17) it can be omitted along with datatype. Like this..
    std::array arr6 {1, 2, 3, 4, 5};            // NOTE: Implicitly typecasted to 'int'
    std::array arr7 { 1.2, 3.4, 5.6, 7.8, 9.0}; // NOTE: Implicitly typecasted to 'double'
    // TIP: Should favour above mentioned method of array declaration.
    std::array arr8 = {1, 2, 3, 4, 5 };         // [Initializer list] also possible!
    // std::array arr9 = {1, 2, 3, 4, 5.0 };    // ERROR: Can't mix 2 datatypes!
    
    std::array<int, MAX> arr10;
    arr10 = {1, 2, 3};                          // Array initialized with 1, 2, 3, 0, 0
    arr10 = {4, 5, 1, 3, 2};                    // Array initialized with 4, 5, 1, 3, 2
    // arr10 = {1, 2, 3, 4, 5, 6};              // ERROR: # of elements more than MAX(5)


    /**
     * NOTE:
     * In statement below -> arr1[i], 'i' is 'int'.
     * Whereas, compiler expects 'i' to be of type 'std::size_type'.
     * IMP: std::size_type is an internal type of std::array - defined inside the definition 
     * of std::array.
     * And, since std::size_type is of type unsigned integral, there are chances of 
     * sign-mismatching when assigning 'int' to 'std::size_type' which results in compiler 
     * throwing warning about signed/unsigned mismatch.
     * 
     * To avoid the warning, create 'i' of type 'std::array<int, MAX>::std::size_type'.
     * 
     * Since, it is NOT very readable, we can replace it with
     * std::size_t (Since, std::size_type is alias for 'std::size_t')
     */
    std::cout << "Printing arr1 (all garbage values)..\n";
    for(int i = 0; i < MAX; ++i) {                                      // Compiler Warning
        std::cout << arr1[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr2 (list initialization)..\n";
    for(std::array<int, MAX>::size_type i = 0; i < arr2.size(); ++i) {  // Works!
        std::cout << arr2[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr3 (initializer list)..\n";
    for(std::size_t i = 0; i < arr2.size(); ++i) {                      // TIP: Best.
        std::cout << arr3[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr6 (int)..\n";
    for(std::size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr6[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr7 (double)..\n";
    for(std::size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr7[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr8 (initializer list)..\n";
    for(std::size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr8[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Printing arr10 (initializer list)..\n";
    for(std::size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr10[i] << ' ';
    }
    std::cout << '\n';

    /**
     * IMP: While accessging std::array values, Subscript operator [] does NOT do any 
     * BOUND-CHECKING.
     * Whereas, at() function does the bound checking. If user tries to access a value which 
     * is out-of-bound via at() operator, of a std::array, it throws exception.
     */
    std::cout << "Last element : " << arr10.at(MAX-1) << '\n';
    std::cout << "Last+1 element : " << arr10[MAX] << '\n';         // Prints garbage
    try {
        std::cout << "Last+1 element : " << arr10.at(MAX) << '\n';  // Throws exception
    } catch(const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
    }



    // SIZE & SORTING
    // .size() function returns size(length) of the std::array
    auto length = arr10.size();
    std::cout << "Length of the array is : " << length << '\n';
    // IMP: Also, as mentioned earlier, std::array does NOT DECAY. Thus, size can also be 
    // accessed inside the functions. Example -
    std::cout << "Fetched length of array : " << getLength(arr10) << '\n';

    std::sort(arr10.begin(), arr10.end());      // Sort forwards
    std::cout << "Printing arr10 (forward sorted)..\n";
    for(std::size_t i = 0; i < length; ++i) {
        std::cout << arr10.at(i) << ' ';
    }
    std::cout << '\n';

    std::sort(arr10.rbegin(), arr10.rend());    // Sort backwards
    std::cout << "Printing arr10 (backward sorted)..\n";
    for(std::size_t i = 0; i < length; ++i) {
        std::cout << arr10.at(i) << ' ';
    }
    std::cout << '\n';



    // ARRAY OF STRUCT
    //TODO:


    // IMP:NOTE: std::array cleans itself up as it goes out of the scope. There's no need any 
    // kind of manual cleanup.
    return 0;
}