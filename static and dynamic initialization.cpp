/**
 * IMP: Initialization of global variables happens as part of program startup, before execution of the main function. 
 * This proceeds in 2 phases -
 * The first phase is called STATIC INITIALIZATION. 
 * In the static initialization phase, global variables with constexpr initializer (including literals) 
 * are initialized to those values. Also, global variables without initializers are zero-initialized.
 * 
 * The second phase is called DYNAMIC INITIALIZATION.
 * This phase is more complex and nuanced, but the gist of it is that global variables with 
 * non-constexpr initializers are initialized.
 */

#include <iostream>
int A();
int B();


int AA { A() };
int BB { B() };


int A() { return BB; }
int B() { return 9; }


int main()
{
    std::cout << AA << BB << '\n';
}

/**
 * This program prints 09 as output.
 * NOTE: Even though, AA & BB are have value initialization done, but since, they are not defined with any literals,
 * they won't be able to statically initialized. They will initialized with 0.
 * During dynamic initialization - AA will call A() which returns value of BB as 0.
 * Thus, cout AA prints 0, followed by 9 which is returned by BB->B().
 */

// TIP: Be careful, not to have variables dependent on the initialization value of other variables that won’t be initialized until later.