#include<iostream>

using namespace std;

int inputX() {
    int x { 0 };
    cout << "Enter X : ";
    cin >> x;
    return x;
}

int inputY() {
    int y { 0 };
    cout << "Enter Y : ";
    cin >> y;
    return y;
}

int sum(int x, int y) {
    return x + y;
}

int main(void) {
    int x { inputX() }; // Cool way of initializing variables. B-)
    int y { inputY() };
    int s { sum(x, y) };
    cout << "Sum = " << s << '\n';

    // cout << "And, one more time..\n";
    // cout << "Sum = " << sum(sum(x,y), sum(x, y));

    return 0;
}