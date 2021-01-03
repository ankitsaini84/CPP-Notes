#include <iostream>

const char* getName() {
    return "Ankit";
    /**
     * IMP: string literals being stored in READ-ONLY memory have 
     * STATIC DURATION rather than having AUTOMATIC DURATION.
     * ~ They die with the end-of-the-program; not with end-of-scope.
     * Thus, if afunction were returning any local variable by address,
     * the variable would be destoryed at the end of the getName(),
     * & we'd return a dandling pointer back to the caller.
     * However, because string literals have STATIC DURATION, "Ankit"
     * will not be destroyed when getName() terminates, so the caller
     * can still successfully access it.
     */
}

int main() {
    char name1[] { "Ankit" };       // Fixed Array
    /**
     * IMP: Here, Compiler allocates a memory space for an array of 5,
     * & initializes that memory with the string "Ankit".
     * Since, this memory has been specifically allocated for 'name1',
     * we can freely manipulate the contents of it.
     */
    const char *name2 { "Ankit" };  // Pointer to symbolic constant
    /**
     * IMP: For Symbolic Constants, this implemetnation is compiler 
     * dependant. 
     * Mostly, compiler places the string "Ankit\0" intoi a READ-ONLY 
     * memory, and then points the pointer to it.
     * 
     * TIP: Since, this memory is READ-ONLY, it's best to make sure that
     * the string is 'const'.
     */


    std::cout << "char name1[] : " << name1 << '\n';
    std::cout << "const char *name2 : " << name2 << '\n';
    std::cout << "getName() : " << getName() << '\n';





    // std::cout & CHAR POINTERS
    constexpr int MAX { 5 };
    int iArray[MAX] { 1, 2, 3 ,4, 5 };
    char cArray[] { "Hello!" };
    const char *name3 { "Ankit" };

    std::cout << "iArray : " << iArray << '\n'; // Prints iArray's addr
    std::cout << "cArray : " << cArray << '\n'; // Prints "Hello!"
    std::cout << "name3 : " << name3 << '\n';
    /**
     * IMP:
     * Question: Why it prints address of iArray, while it prints 
     * contents of the char* when we cout cArray ?
     * Answer: std::cout treats int* & char* differently.
     * When we pass it a non-char pointer, it will simply print the
     * contents of that pointer.
     * On the contrary, when a char pointer is passed, it assumes that
     * you're intending to print a string & thus, prints the string being
     * pointed to, instead.
     */

    return 0;
}