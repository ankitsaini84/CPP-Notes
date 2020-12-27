// NOTE: This file is only being used as helping file 'external linkage.cpp'
// To refer EXTERNAL LINKAGE - visit 'external linkage.cpp'
// To refer INTERNAL LINKAGE - visit 'global variables.cpp' & 'functions.cpp'

int getX();     // Forward declaration - notation for compiler that definition for getX() exists somewhere. Linker will link it later.

extern int g_a;             // IMP: 'extern' - this is a forward declaration for an external variable that is defined somewhere else
extern const int g_y;       // IMP: 'extern' - this is a forward declaration for an external variable that is defined somewhere else
// extern constexpr int g_z;// ERROR: 'constexpr' variables can't be forward declared

// NOTE: To see the definitions - refer 'linkage.cpp'.