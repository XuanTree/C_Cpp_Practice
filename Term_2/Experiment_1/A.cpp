#include <cmath>
#include <ios>
#include <iostream>
#include <iomanip>

class Circle {
    private:
        double r;
    public:
        void input();
        double area() const;
        void output() const;
};

void Circle::input() {
    std::cin >> this->r;
}

double Circle::area() const {
    const double PI = std::acos(-1.0);
    return this->r * this->r * PI;
}

void Circle::output() const {
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << Circle::area();
}

int main ( ) {
    Circle circle = Circle();
    circle.input();
    circle.area();
    circle.output();
    return 0;
}