#pragma once

#include <iostream>

class Complex {
private:
	double a;
	double b;
public:
	Complex() {}
	Complex(const Complex& _complex) {
		Complex complex;
		complex = _complex;
	}
	Complex(double _a, double _b) : a(_a), b(_b) {}

	double getRealPart() const;
	double getVirtPart() const;
	void setRealPart(const double _a);
	void setVirtPart(const double _b);

	Complex& operator+(const Complex& complex);
	Complex& operator-(const Complex& complex);
	Complex operator*(const Complex& complex);
	Complex operator/(const Complex& complex);

	friend std::ostream& operator<<(std::ostream& os, Complex& complex);
	friend std::istream& operator>>(std::istream& is, Complex& complex);
};