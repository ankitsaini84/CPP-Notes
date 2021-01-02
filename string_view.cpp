#include <iostream>
#include <string_view>  // std::string_view
#include <cstring>      // std::strncpy()
#include <iterator>     // std::size()
#include <string>       // std::getline()

std::string_view getSV() {
    std::cout << "Enter your Name : ";
    std::string name {};
    std::getline(std::cin, name);

    // NOTE: Switching to string_view - only for demonstrative purpose.
    std::string_view view { name };
    std::cout << "Hello " << name << '\n';

    return view;
}   // IMP: name dies here and so does the view it created (view).

int main() {
    char arr[] { "Hello!" };
    // IMP: Creates a string literal "Hello!" (known at compile time 
    // & stored as binary).
    // @ Run-time : Allocates memory to 'arr' & copies this string 
    // literal to it.

    std::string str1 { arr };
    // @ Run-time : Alloctes memory to 'str1' & copies contents of arr 
    // to it.
    
    std::string str2 { str1 };
    // @ Run-time : Allocates memory to 'str2' & copies contents of 
    // str1 to it.

    // NOTE: In all, above code-snippet creates 4 copies of "Hello!", 
    // first being the string literal itself and then copying it 3 times 
    // over to 'arr', ;str1' & 'str2'.
    std::cout << arr << ' ' << str1 << ' ' << str2 << '\n';

    // String View
    std::string_view sv_arr { "Hello!" };
    std::string_view sv_str1 { sv_arr };
    std::string_view sv_str2 { sv_str1 };

    // IMP: Though! the output will be same as above, no more copies of 
    // "Hello!" are being made. At run-time, no new memory is allocated, 
    // as sv_arr is just a view to string literal "Hello!". Also, when 
    // sv_arr is assigned to sv_str1, sv_str1 also starts observing same 
    // string literal "Hello!" & no new copy is created.
    std::cout << sv_arr << ' ' << sv_str1 << ' ' << sv_str2 << '\n';

    // Functions supported by string_view
    // NOTE: Manipulating string views changes only the view of the 
    // string, and not the actual string.
    sv_str1.remove_prefix(1);   // Remove 1st character
    std::cout << "Revomed 1 prefix : " << sv_str1 << '\n';
    std::cout << "Data View : " << sv_str1.data() << '\n';
    sv_str1.remove_suffix(2);   // Remove last 2 characters
    std::cout << "Revomed 2 suffixes : " << sv_str1 << '\n';
    std::cout << "Data View : " << sv_str1.data() << '\n';  // ERROR:
    std::cout << "Actual String : " << sv_arr << '\n';  // As-is actual str
    
    
    // Other supported functions..
    std::cout << "Length of sv_arr : " << sv_arr.length() << '\n';
    std::cout << "Sub String : " << sv_arr.substr(0, sv_arr.find('o'))
    << '\n';

    // NOTE: Changes made to the original string, reflect to the views.
    std::string_view sv_str4 { arr };
    std::cout << "String View [Before Change] : " << sv_str4 << '\n';
    std::strncpy(arr, "hehaha", std::size(arr));
    std::cout << "String View [After Change] : " << sv_str4 << '\n';




    // IMP: Unlike C-style strings & std::string, std::string_view doesn't 
    // use NULL TERMINATORS to mark END OF STRING. Rather, it knows where 
    // the string eans as it keeps track of the length of the string.
    // Thus, it works w/ non-null terminated strings
    char myName[] { 'A', 'n', 'k', 'i', 't' };
    std::string_view sv_name { myName, std::size(myName)};
    std::cout << "My Name : \'" << myName << "\'\n";
    // ERROR: There seems to be an error in g++ compiler's implementation 
    // of string_view as it is printing 'Ankit<junk>'. It seems to be 
    // considering length as {# of chars + 1} which is contradictory.



    // Conversion to c-style string & std::string
    std::string strName { sv_name };        // string_view to std::string
    auto cStyleName { strName.c_str() };    // std::string to C-string
    std::cout << "String Name : " << strName << '\n';
    std::cout << "C-Style Name : " << cStyleName << '\n';
    // TIP: Avoid C-style conversion as it's expensive.


    // Ownership issue - Scope of string_view
    std::string_view sv_oos { getSV() };
    // IMP: Undefined Behaviour : Here, 'sv_oos' is observing a string 
    // which is out-of-scope for it, as the scope of the string it wants 
    // to observe is limited to the function getSV() only. Thus, following 
    // cout will print junk characters.
    std::cout << "Hello " << sv_oos << '\n';
    return 0;
}