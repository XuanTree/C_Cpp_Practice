#include <iostream>
#define PI 3.142

class Shape {
protected:
    double x = -1;
public:
    Shape() = default;
    Shape(double _x) : x(_x) {};
    ~Shape() {}

    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class Circle : public Shape{
public:
    Circle() = default;
    Circle(double _r) : Shape(_r) {}
    double getArea() override;
    double getPerimeter() override;
    friend double operator-(const Circle& c1, const Circle& c2);
};

double Circle::getArea() {
    return PI * this->x * this->x;
}

double Circle::getPerimeter() {
    return 2 * PI * this->x;
}

double operator-(const Circle& c1, const Circle& c2) {
    return PI * c1.x * c1.x - PI * c2.x * c2.x;
}

class Rectangle : public Shape {
private:
    double y;
public:
    Rectangle() = default;
    Rectangle(double _x, double _y) : Shape( _x), y(_y) {}
    double getArea() override;
    double getPerimeter() override;
};

double Rectangle::getArea() {
    return this->x * this->y;
}

double Rectangle::getPerimeter() {
    return 2 * (this->x + this->y);
}

int main () {
    double r1, r2;
    std::cin >> r1 >> r2;

    Circle c1(r1);
    Circle c2(r2);

    std::cout << c1 - c2 << std::endl;

    Rectangle rec(r1,r2);
    std::cout << rec.getArea() << std::endl << rec.getPerimeter() << std::endl;
    return 0;
}