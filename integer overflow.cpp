#include <iostream>

int main() {
    /**
     * Notes ~ By definintion, unsigned integers CANNOT overflow.
     * Instead - if the assigned vaue is out-of-range, it is divided by 1 greater 
     * than the largest number of the type, and only the remainder is kept..
     */
    unsigned int a { 65537 };
    unsigned short b { a };
    std::cout << "b : " << b << '\n';
    /**
     * Interesting Note :-
     * Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers.
     * This is largely because of two behaviors that can cause problems.
     * 
     * First, consider the subtraction of two unsigned numbers, such as 3 and 5. 3 minus 5 is -2, 
     * but -2 can’t be represented as an unsigned number. 
     * Example :-
     */
    unsigned int x {3};
    unsigned int y {5};
    unsigned int z = x - y;
    std::cout << "x : " << z << '\n';
    /**
     * Second, unexpected behavior can result when you mix signed and unsigned integers. 
     */
    return 0;
}