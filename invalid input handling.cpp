#include <iostream>
#include <limits>

/**
 * IMP: HOW CIN WORKS..
 * When we use >> operator to get user input & put it into a 
 * variable, this is called EXTRACTION OPERATOR.
 * When user enters input in response to an extraction operation, that data
 * is placed in a DATA BUFFER inside of std::cin. This buffer is used to 
 * holduser input while it's waiting to be extracted to variables.
 * 
 * When extraction operator is used, following procedure is followed:
 * #1. If there's data already in i/p buffer, it is used for extraction.
 * #2. If there's no data, user is asked to i/p data for extraction.
 *     When user hits Enter, a '\n' is places in the i/p buffer.
 * #3. Operator >> extracts as much data from i/p buffer. 
 *     (while ignoring any leading whitespaces, tabs & newline characters)
 * #4. Any data that can not be extracted, is left in i/p buffer for next 
 *     extraction.
 * 
 * Extraction succeeds, if at least 1 character is extracted from the i/p 
 * buffer.
 */
void explainCinWorkings() {
    int x {};
    std::cout << "Type 5a : ";
    std::cin >> x;                          // Only '5' is extracted.
    
    std::cout << "Value of 'x' : " << x << '\n';
    // NOTE: Above statement, shall print '5' & "a\n" is still left in 
    // input buffer.

    std::cin >> x;
    // NOTE: cin shall extract remaining "a\n", but since, 'a' can not be
    // assigned to datatype 'int', thus, extraction fails & cin returns 0.
    
    std::cout << "Left buffer from previous cin : " << x << '\n';
    // Above statement prints '0'.
}

// ERROR HANDLING with std::cin..
/**
 * IMP: Input text error can be of 4 types:
 * #1. Input extraction succeeds but the input is meaningless to the
 *     program (e.g. entering ‘k’ as your mathematical operator).
 * #2. Input extraction succeeds but the user enters additional input 
 *     (e.g. entering ‘*q hello’ as your mathematical operator).
 * #3. Input extraction fails (e.g. trying to enter ‘q’ into a numeric input).
 * #4. Input extraction succeeds but the user overflows a numeric value.
 */

class Calculator {
    double  m_operand1;
    double  m_operand2;
    char    m_operator;

    double getOperand(const int operandCount) {
        double t;
        while(true) {                           // Loop until there's a valid input
            std::cout << "Enter Operand #" << operandCount << " : ";
            std::cin >> t;
            
            if(std::cin.fail()) {               // Check whether cin failed
                std::cin.clear();               // Put us back in normal op. mode
                std::cin.ignore(32767, '\n');   // remove bad input
            } else {
                // Clear (upto 32767) chars out of buffer until a '\n' is removed.
                std::cin.ignore(32767, '\n');
                return t;                       // return extracted value
            }
        }
    }

    char getOperator() {
        char t;
        while(true) {                           // Loop until there's a valid input
            std::cout << "Enter Operator [+, -, *, /] : ";
            std::cin >> t;
            switch(t) {                         // Validate user input
                case '+': [[fallthrough]];
                case '-': [[fallthrough]];
                case '*': [[fallthrough]];
                case '/': return t;             // Return operand
                default : {                     // Invalid input
                // Clear complete input buffer until '\n' is removed from buffer.
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid Operator! Try Again.\n";
                }
            }
        }
    }

    public:
    Calculator() :  m_operand1(getOperand(1)), 
                    m_operand2(getOperand(2)),
                    m_operator(getOperator()) {}
    
    void evaluate() {
        std::cout << "Result : ";
        switch(m_operator) {
            case '+': {
                std::cout << m_operand1 + m_operand2;
                break;
            }
            case '-': {
                std::cout << m_operand1 - m_operand2;
                break;
            }
            case '*': {
                std::cout << m_operand1 * m_operand2;
                break;
            }
            case '/': {
                std::cout << m_operand1 / m_operand2;
                break;
            }
        }
        std::cout << '\n';
    }
};

int main() {
    // explainCinWorkings();
    Calculator calc;
    calc.evaluate();
    return 0;
}
