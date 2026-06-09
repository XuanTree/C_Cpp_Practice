#include "../include/Operators.h"

// =====================================
//			Complex复数类实现
// =====================================

double Complex::getRealPart() const { return a; }
double Complex::getVirtPart() const { return b; }

void Complex::setRealPart(const double _a) { a = _a; }
void Complex::setVirtPart(const double _b) { b = _b; }

Complex& Complex::operator+(const Complex &complex) {
  a = a + complex.getRealPart();
  b = b + complex.getVirtPart();
  return *this;
}

Complex& Complex::operator-(const Complex &complex) {
  a = a - complex.getRealPart();
  b = b - complex.getVirtPart();
  return *this;
}

Complex Complex::operator*(const Complex &complex) {
  Complex result;
  double result_a = (a * complex.a - b * complex.b);
  double result_b = (a * complex.b + b * complex.a);
  result.setRealPart(result_a);
  result.setVirtPart(result_b);

  return result;
}

Complex Complex::operator/(const Complex &complex) {
  if (complex.a == 0 && complex.b == 0) {
    std::cerr << "Error: Can not devided by ZERO!" << std::endl;
    return Complex();
  }

  Complex result;
  double result_a = (a * complex.a + b * complex.b) /
                    (complex.a * complex.a + complex.b * complex.b);
  double result_b = (b * complex.a - a * complex.b) /
                    (complex.a * complex.a + complex.b * complex.b);
  result.setRealPart(result_a);
  result.setVirtPart(result_b);

  return result;
}

std::ostream &operator<<(std::ostream &os, Complex &complex) {
  if (complex.getVirtPart() < 0) {
    os << complex.getRealPart() << complex.getVirtPart() << "i" << std::endl;
  } else if (complex.getVirtPart() == 0) {
    os << complex.getRealPart() << std::endl;
  } else {
    os << complex.getRealPart() << "+" << complex.getVirtPart() << "i"
       << std::endl;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Complex &complex) {
  is >> complex.a >> complex.b;
  return is;
}
