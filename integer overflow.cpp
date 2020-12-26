#include <iostream>

int main() {
    /**
     * IMP: Integer overflow (often called overflow for short) occurs when we try to store a value 
     * that is outside the range of the type. Essentially, the number we are trying to store
     * requires more bits to represent than the object has available. In such a case, data is
     * lost because the object doesn’t have enough memory to store everything.
     * 
     * IMP: In the case of SIGNED INTEGERS, which bits are lost is not well defined, 
     * thus signed integer overflow leads to undefined behavior.
     */

    /**
     * IMP: By definintion, UNSIGNED INTEGERS CANNOT overflow.
     * Instead - if the assigned vaue is out-of-range, it is divided by 1 greater 
     * than the largest number of the type, and only the remainder is kept..
     */
    unsigned int a { 65537 };
    unsigned short b { a };
    std::cout << "b : " << b << '\n';
    /**
     * NOTE: Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers.
     * This is largely because of two behaviors that can cause problems.
     * 
     * First, consider the subtraction of two unsigned numbers, such as 3 and 5. 3 minus 5 is -2, 
     * but -2 can’t be represented as an unsigned number. 
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