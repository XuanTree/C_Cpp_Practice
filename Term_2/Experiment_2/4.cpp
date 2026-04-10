#include <iostream>
#include <cmath>

class Point2 {
    protected:
        double x;
        double y;
    public: 
        Point2(double x, double y);
        double getY();
        double getX();
};

double Point2::getX() {
    return this->x;
}

double Point2::getY() {
    return this->y;
}

Point2::Point2(double _x, double _y) : x(_x), y(_y) { }

class Line2 {
    private:
        Point2 point2_1;
        Point2 point2_2;
    public:
        Line2(Point2 point2_1, Point2 point2_2);
        double Length();
};

Line2::Line2(Point2 _point2_1, Point2 _point2_2) : point2_1(_point2_1), point2_2(_point2_2) {}

double Line2::Length() {
    return std::sqrt(std::pow((point2_2.getY() - point2_1.getY()), 2) + std::pow(point2_2.getX() - point2_1.getX(), 2));
}

int main() {
    Point2 pt1(1.0, 1.0);
    Point2 pt2(3.0, 4.0);
    Line2 line(pt1, pt2);
    std::cout << line.Length() << std::endl;

    double x1,y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line2 nLine(Point2(x1, y1), Point2(x2, y2));
    std::cout << nLine.Length()<< std::endl;

    return 0;
}