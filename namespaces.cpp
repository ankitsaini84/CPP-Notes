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
 
using namespace std; // makes std::cout accessible as "cout"
 
int cout() // declares our own "cout" function
{
    return 0;
}
 
int main()
{
    cout << "Hello, world!"; // Compile error!  
    // Which cout do we want here?  
    // The one in the std namespace or the one we defined above?
    return 0;
}

/**
 * IMP:
 * The above program doesn’t compile, because the compiler now can’t tell whether we want 
 * the 'cout' function that we defined, or the 'cout' that is defined inside the 'std namespace'. 
 * When using a 'using directive' in this manner, any identifier we define may conflict with 
 * any identically named identifier in the std namespace. Even worse, while an identifier 
 * name may not conflict today, it may conflict with new identifiers added to the 'std 
 * namespace' in future language revisions. This was the whole point of moving all of the 
 * identifiers in the standard library into the 'std namespace' in the first place!
 */

/**
 * TIP:- Avoid using directives (such as using namespace std;) at the top of your program. 
 * They violate the reason why namespaces were added in the first place. 
 */