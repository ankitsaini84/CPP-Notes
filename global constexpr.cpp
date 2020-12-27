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