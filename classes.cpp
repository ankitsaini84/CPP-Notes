#include <iostream>
#include <array>
class Date {
    int m_year {};
    int m_month {};
    int m_day {};
    
    public:
    Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {}

    void print() {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

int main() {
    Date today {2020, 12, 21};
    today.print();
    return 0;
}