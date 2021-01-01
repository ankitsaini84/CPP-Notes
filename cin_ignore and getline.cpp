#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string name {};
    std::string age {};

    std::cout << "Enter your Full Name : ";
    std::cin >> name;
    // NOTE: >> operator in cin only reads buffer till it encounters a
    // whitespace, \t or \n. Thus, as it encounters a whitespace, it breaks
    // the i/p and only reads the firstname & leaves the rest in the buffer
    // to be fetched next time.
    
    std::cout << "Enter you age : ";
    std::cin >> age;
    // NOTE: This time, cin encounters that buffer still has remaining 
    // name & \n, from last cin. So, it fetches that & moves ahead - Not
    // giving user to input his/her age.

    std::cout << '\n';
    std::cout << "Full Name : " << name << '\n';
    std::cout << "Age : " << age << '\n';




    std::cout << "\nOops! Let's try again..\n";
    // Clear buffer for next try.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    name = "";
    age = "";

    // Using getline() to read whole input.
    std::cout << "Enter your Full Name : ";
    getline(std::cin, name);
    // NOTE: Now, getline is able to read whole line as input in one go.

    std::cout << "Enter you age : ";
    std::cin >> age;

    std::cout << "Full Name : " << name << '\n';
    std::cout << "Age : " << age << '\n';




    std::cout << "\nYay! We did GREAT last time. "
    << "But, Let's shake things up..\n";

    int iAge {};
    std::cout << "Enter your Age : ";
    std::cin >> iAge;
    // NOTE: cin fetches whole string till it encounters '\n' & converts it
    // to int & assigns it to iAge. 
    // BUT, it leaves '\n' in buffer!

    std::cout << "Enter your Full Name : ";
    getline(std::cin, name);
    // NOTE: getline() finds a '\n' in buffer & thinks, it's the whole 
    // line. Remember, IMP: it does NOT skip leading '\n',  '\t' & 
    // whitespaces, like cin. 
    // Thus, it accepts the i/p & moves on - skipping user input.

    std::cout << "Full Name : " << name << '\n';
    std::cout << "Age : " << iAge << '\n';



    std::cout << "\nTold you! This time we'll do GREAT. "
    << "Promise.\n";

    std::cout << "Enter your Age : ";
    std::cin >> iAge;
    std::cin.ignore(32767, '\n');
    // NOTE: Flush out cin buffer (leftover '\n') after fecthing int.

    std::cout << "Enter your Full Name : ";
    getline(std::cin, name);

    std::cout << "Full Name : " << name << '\n';
    std::cout << "Age : " << iAge << '\n';

    return 0;
}