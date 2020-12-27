#ifndef OTHERFILE_H
#define OTHERFILE_H
 
// Forward declarations:
 
// Function forward declarations:
void functionOne(int functionParameter);
                    
// Non-constant global variable forward declarations:
extern int g_var;
extern int g_internalVar; // Not forward declared because internal
                    
// Const global variable forward declarations:
extern const int g_constVar; // Not forward declared because internal
extern const int g_externalConstVar;
// extern inline const int g_inlineConstVar{ 8 }; // 6.8: "The inline variable
                                               // definition (not a forward 
                                               // declaration) must be present
                                               // in any file that uses the 
                                               // variable."
                    
// Constexpr global variable forward declarations (NOT ALLOWED):
/* extern constexpr int g_constexprVar;
   extern constexpr int g_externConstexprVar;
   extern inline constexpr int g_inlineConstexprVar{ 11 }; */
                    
#endif