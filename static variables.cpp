/**
 * IMP:
 * STATIC DURATION - created when program starts & destroyed when program exits.
 * AUTOMATIC DURATION - created when defined & destroyed when block is exited.
 * All global varibale shave static duration.
 * All local variables have automatic duration.
 * Using 'static' keyword w/ local variable changes its duration to STATIC DURATION.
 * 
 * INTERNAL LINKAGE - identifier can only be used in the file in which it is defined.
 * Using 'static' keyword w/ global identifier changes its linkage to INTERNAL LINKAGE.
 */

#include <iostream>
 
void incrementAndPrint1()
{
    int value { 1 };                // AUTOMATIC DURATION by default
    ++value;
    std::cout << value << '\n';
}                                   // 'value' is destroyed here

void incrementAndPrint2()
{
    static int s_value { 1 };       // STATIC DURATION
    ++s_value;
    std::cout << s_value << '\n';
}                                   // 's_value' is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    std::cout << "Auto duration..\n";
    incrementAndPrint1();
    incrementAndPrint1();
    incrementAndPrint1();
    std::cout << "Static duration..\n";
    incrementAndPrint2();
    incrementAndPrint2();
    incrementAndPrint2();

    return 0;
}