#pragma once
#include <iostream>

template<typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T1, typename T2>
class SimpleCalculator {
private:
	T1 x;
	T2 y;
public:
	SimpleCalculator() {}
	SimpleCalculator<T1, T2>(T1 x, T2 y) : x(x), y(y) {}

	const T1 getX() const;
	const T2 getY() const;
	
	void Plus() const;
	void Minus() const;
	void Multiply() const;
	void Devide() const;
};


