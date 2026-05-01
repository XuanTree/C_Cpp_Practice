#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

class Complex {
private:
  double x;
  double y;

public:
  Complex(double x = 0.0, double y = 0.0);

  Complex &operator+=(const Complex &);

  Complex &operator-=(const Complex &);

  Complex &operator*=(const Complex &);

  Complex &operator/=(const Complex &);

  friend Complex operator+(const Complex &, const Complex &);

  friend Complex operator-(const Complex &, const Complex &);

  friend Complex operator*(const Complex &, const Complex &);

  friend Complex operator/(const Complex &, const Complex &);

  friend bool operator==(const Complex &, const Complex &);

  friend bool operator!=(const Complex &, const Complex &);

  friend ostream &operator<<(ostream &, const Complex &);

  friend istream &operator>>(istream &, Complex &);
};

istream& operator>>(istream& is, Complex& c) {
    is >> c.x >> c.y;
    return is;
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.x << " + " << c.y << "i";
    return os;
}

Complex::Complex(double x, double y) : x(x), y(y) {};

Complex& Complex::operator+=(const Complex& c) {
    this->x += c.x;
    this->y += c.y;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    this->x -= c.x;
    this->y -= c.y;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    double temp = x;
    this->x = x * c.x - y * c.y;
    this->y = temp * c.y + y * c.x;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    double b = c.x * c.x + c.y * c.y;
    double temp = x; // 难绷了，不能直接用 x，因为 x 的值会被修改掉
    this->x = (x * c.x + y * c.y) / b;
    this->y = (y * c.x - temp * c.y) / b;
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.x + c2.x, c1.y + c2.y);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.x - c2.x, c1.y - c2.y);
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.x * c2.x - c1.y * c2.y, c1.x * c2.y + c1.y * c2.x);
}

Complex operator/(const Complex& c1, const Complex& c2) {
    double b = c2.x * c2.x + c2.y * c2.y;
    return Complex((c1.x * c2.x + c1.y * c2.y) / b, (c1.y * c2.x - c1.x * c2.y) / b);
}

bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.x == c2.x) && (c1.y == c2.y);
}

bool operator!=(const Complex& c1, const Complex& c2) {
    return (c1.x != c2.x) || (c1.y != c2.y);
}

int main() {
  Complex c1, c2;

  cin >> c1 >> c2;

  cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;

  cout << "c1+c2 = " << c1 + c2 << endl;

  cout << "c1-c2 = " << c1 - c2 << endl;

  cout << "c1*c2 = " << c1 * c2 << endl;

  cout << "c1/c2 = " << c1 / c2 << endl;

  cout << (c1 += c2) << endl;

  cout << (c1 -= c2) << endl;

  cout << (c1 *= c2) << endl;

  cout << (c1 /= c2) << endl;

  cout << (c1 == c2) << " " << (c1 != c2) << endl;

  return 0;
}