/**
 * using namespace std;
 * cout << "Hello";
 * NOTE: A 'using directive' tells the compiler to check a specified namespace 
 * when trying to resolve an identifier that has no namespace prefix. 
 * 
 * So in the above example, when the compiler goes to determine what 
 * identifier 'cout', it will check both locally (where it is undefined) 
 * and in the std namespace (where it will match to std::cout).
 */

#include <iostream> // imports the declaration of std::cout
#include "constants.h"

// USING NAMESPACE DIRECTIVE
// TIP: Avoid using directives (such as using namespace std;) at the top 
// of your program. They violate the reason why namespace were added in 
// the first place. 
using namespace std;    // makes std::cout accessible as "cout"

int cout()              // declares our own "cout" function
{
    return 0;
}

// GLOBAL NAMESAPCES
// NOTE: Anything which is explicityly not declared/defined as part of a 
// namespace is part of global namespace.
void print() {
    std::cout << "global namespace's print()\n";
}

// NESTED NAMESAPCES
// Namesapces can be nested inside each-other.
namespace foo {
    void print() {
        std::cout << "foo namespace's print()\n";
    }

    namespace goo {
        void print() {
            std::cout << "goo namespace's print()\n";
        }
    }
}

// NAMESPACE ALIAS
namespace zoo = foo::goo;   // Defines 'zoo' as alias for foo::goo

// UN-NAMED NAMESPACES
// NOTE: All content declared in unnamed namespace is treated as if it is 
// part of parent namespace. Thus, content from unnamed namespaces can be 
// accessed as if it is part of global namespace BUT without global scope 
// & can ne called within the file without any qualifiers.
// IMP: This property of unnamed namespaces make them have INTERNAL LINKAGE
namespace {
    void helloWorld() {
        std::cout << "Hello from unnamed namespace!\n";
    }
}

// INLINE NAMESAPCES
// These are used for versioning content.
// Anything decalred inside inline namespace is considered a part of the 
// parent namespace. However, it don't give everything internal linkage.
inline namespace v1 {       // Default Namespace for doSomething()
    void doSomething() {
        std::cout << "v1 doing something\n";
    }
}

namespace v2 {
    void doSomething() {
        std::cout << "v2 doing something\n";
    }
}

int main()
{
    // cout << "Hello, world!"; // ERROR: Compile error!
    /**
     * NOTE:
     * Which cout do we want here - The one in the std namespace or the 
     * one we defined above? The code program doesn’t compile, because the 
     * compiler now can’t tell whether we want the 'cout' function that we 
     * defined, or the 'cout' that is defined inside the 'std namespace'. 
     * When using a 'using directive' in this manner, any identifier we 
     * define may conflict with any identically named identifier in the 
     * std namespace. Even worse, while an identifier name may not 
     * conflict today, it may conflict with new identifiers added to the 
     * 'std namespace' in future language revisions. This was the whole 
     * point of moving all of the identifiers in the standard library into 
     * the 'std namespace' in the first place!
     */  
    
    ::print();          // Calls global namespace's print()
    foo::print();       // Calls foo namespace's print()
    foo::goo::print();  // Calls goo namespace's print()
    zoo::print();       // zoo is alias of goo.
    std::cout << "Accessing gravity value from constants namesapce : " << constants::gravity << '\n';
    
    helloWorld();       // Calls unnamed namespace's helloWorld()

    v1::doSomething();  // Calls v1 namesapce's doSomething()
    v2::doSomething();  // Calls v2 namesapce's doSomething()
    doSomething();      // Calls v1 namesapce's doSomething() - as default

    return 0;
}