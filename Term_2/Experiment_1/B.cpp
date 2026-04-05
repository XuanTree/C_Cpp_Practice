#include <iostream>

class Rectangle {
    private:
        double length;
        double width;
    public: 
        Rectangle(double Length = 10., double Width = 5.);
        double Area( ) const;
        double Perimeter( ) const;
};

Rectangle::Rectangle(double Length, double Width) : length(Length), width(Width) {}

double Rectangle::Area() const {
    return length * width;
}

double Rectangle::Perimeter() const {
    return 2 * (length + width);
}
int main () {
    double new_length; double new_width;
    std::cin >> new_length >> new_width;
    Rectangle rect1 = Rectangle(new_length,new_width);
    Rectangle rect2 = Rectangle(new_length+3.,new_width+3.);
    std::cout << rect2.Perimeter() * 50. << std::endl;
    std::cout << (rect2.Area() - rect1.Area()) * 240. << std::endl;
    return 0;
}