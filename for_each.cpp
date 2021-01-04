/**
 * NOTE: FOR-EACH loops are also known as RANGE-BASED FOR-LOOPS
 * Syntax - 
 * for(element_declaration : array)
 *     statement;
 * 
 * The loop wil iterate through each element in array, assigning the value of the current
 * array element to the variable decalred in element_declaration.
 * TIP: For best results, element_decalaration should always have the same type as the array 
 * elements, otherwise type conversion will occur for each element.
 */

#include <iostream>

int main() {
    constexpr int fibonacci[] {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    std::cout << "Iterating each element of fibonacci series ..\n";
    for(auto number: fibonacci) {       // TIP: Keyword 'auto' use - Good practice
    // It's a good practice to use auto here, so that element_declaration type matches the 
    // type of the elements of the array.
        std::cout << number << ' ';
    }
    std::cout << '\n';

    /**
     * IMP:TIP:
     * #1. For-each loop work with list-like structures like
     * Vectors,
     * Linked lists,
     * Trees &
     * Maps.
     * 
     * #2. They don't work with pointers to an array, though.
     * 
     * #3. For-each don't provide a direct way to get the array index of the current element.
     */

    return 0;
}


