/**
 * Alert            \a 	Makes an alert, such as a beep
 * Backspace 	    \b 	Moves the cursor back one space
 * Formfeed     	\f 	Moves the cursor to next logical page
 * Newline 	        \n 	Moves cursor to next line
 * Carriage return 	\r 	Moves cursor to beginning of line
 * Horizontal tab 	\t 	Prints a horizontal tab
 * Vertical tab 	\v 	Prints a vertical tab
 * Single quote 	\’ 	Prints a single quote
 * Double quote 	\” 	Prints a double quote
 * Backslash 	    \\ 	Prints a backslash.
 * Question mark 	\? 	Prints a question mark. [No longer relevant. You can use question marks unescaped.]
 * Octal number 	\(number) 	Translates into char represented by octal
 * Hex number 	    \x(number) 	Translates into char represented by hex number
 */

#include <iostream>

int main() {
    char ch {' '};
    while(ch != '.') {
        std::cout << "Enter anything : ";   // Try a sentence with '.' at the end.
        // Notice, that 'cin' takes only a single character as input and rest of the charaters in the 
        // sentence are queued up for next cin statement.
        std::cin >> ch;
        // Here, '/r' in following statement is a cariage return used to write 
        // over previous cout statement - 'Enter anything :'. It shows a continuous
        // flow of 'ASCII value ..' statements without showing 'Enter anything' statement.
        std::cout << "\rASCII value of \'" << ch << "\' is " << static_cast<int>(ch) << '\n';
    }
    return 0;
}