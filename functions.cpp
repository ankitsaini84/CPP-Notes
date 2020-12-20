#include<iostream>

int inputX() {
    int x { 0 };
    std::cout << "Enter X : ";
    std::cin >> x;
    return x;
}

int inputY() {
    int y { 0 };
    std::cout << "Enter Y : ";
    std::cin >> y;
    return y;
}

int sum(int x, int y) {
    return x + y;
}

int main(void) {
    int x { inputX() }; // Cool way of initializing variables. B-)
    int y { inputY() };
    int s { sum(x, y) };
    std::cout << "Sum = " << s << '\n';

    // std::cout << "And, one more time..\n";
    // std::cout << "Sum = " << sum(sum(x,y), sum(x, y));

    return 0;
}