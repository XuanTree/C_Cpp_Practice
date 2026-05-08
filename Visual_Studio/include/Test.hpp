#pragma once

class Test {
private:
	int a;
public:
	Test() = default;
	explicit Test(const int a) : a(a) {};
	void print() const;
};

template<typename T>
class PrintThings {
private:
	T variable;
public:
	explicit PrintThings(T thing);
	void Print() const;
};

template<typename T>
class SwapTwoThings {
private:
	T* variable1;
	T* variable2;
public:
	SwapTwoThings() = delete;
	SwapTwoThings(T& var1, T& var2);
	void Swap();
};
