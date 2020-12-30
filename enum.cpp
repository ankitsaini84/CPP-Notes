#include <iostream>

// Forward Decalaring enum type.
// enum Color;      // ERROR: This won't work. Type must be defined.
enum Color : int;   // NOTE: Define type (int)

// Definiting enum type
enum Color : int {  // NOTE: Must re-define type (int) when defining.
    color_onyx      = -1,   // Allowed to assign -ve values (int)
    color_black     = 0,
    color_white     = 1,
    color_red       = 2,
    color_blue      = 3,
    color_green     = 4,
    color_yellow    = 5,
    color_pink      = 5,    // Allowed to reassign same value. 
    // TIP: Avoid re-assigning same value, though.
    color_orange    = 6,
};

enum Balloon : unsigned int {
    // color_red       = 1, // ERROR: Conflicts with previous 'color_red'
    // IMP: Since, both enum values of 'color_red' are in same global 
    // namesapce - they will conflict with each other.
    balloon_red     = 1,    // Works!
    // balloon_blue    = -1,// ERROR: enum type is 'unsigned int'.
    // Thus, can only be assigned positive integers as value.
};

// IMP:TIP: Don’t assign specific values to your enumerators.

// NOTE: Following is a nice way to return enum values.
std::string getColor(const int c) {
    std::string color {};
    switch(c) {
        case -1 : color = "Onyx"; break;
        case 0  : color = "Black"; break;
        case 1  : color = "White"; break;
        case 2  : color = "Red"; break;
        case 3  : color = "Blue"; break;
        case 4  : color = "Green"; break;
        case 5  : color = "Yellow"; break;
        // case 5  : color = "Pink"; break;
        case 6  : color = "Orange"; break;
        default : color = "Invalid Color";
    }
    return color;
}

int main() {
    int balloon {color_red};// Assign color_red (Color enum) to int.

    // Color c { 1 };       // ERROR: Can't assign int to type Color.
    Color c {static_cast<Color>(1)};    // Must explicitly cast it.

    // std::cin << c;       // ERROR: Can't use cin to input enum value.
    // Work around..
    int inputColor {};
    std::cout << "Enter Color [-1 - 6] : ";
    std::cin >> inputColor;
    c = static_cast<Color>(inputColor);

    std::cout << "Inputed Color Value : " << c << '\n';
    std::cout << "Inputed Color Name  : " << getColor(c) << '\n';
    if(c == color_red) {
        std::cout << "It's the same color as my balloon. :)\n";
    }
    
    return 0;
}