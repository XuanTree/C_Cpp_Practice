#include <iostream>
#include <utility>
#include "Test.hpp"

void Test::print() const {
	std::cout << "a = " << a << std::endl;
}

template <typename T>
PrintThings<T>::PrintThings(T thing) : variable(std::move(thing)) {}

template <typename T>
void PrintThings<T>::Print() const {
	std::cout << this->variable << std::endl;
}

// 显式实例化（必须在成员函数定义之后）
template class PrintThings<int>;
template class PrintThings<std::string>;
template class PrintThings<double>;
template class PrintThings<char>;
template class PrintThings<char*>;

template<typename T>
SwapTwoThings<T>::SwapTwoThings(T& var1, T& var2) : variable1(var1), variable2(var2) {}

template<typename T>
void SwapTwoThings<T>::Swap() {
	T temp = std::move(variable1);
	variable1 = std::move(variable2);
	variable2 = std::move(temp);

	std::cout << "Swapped Successfully!" << std::endl;
}

template class SwapTwoThings<int>;
template class SwapTwoThings<double>;
template class SwapTwoThings<char>;
template class SwapTwoThings<char*>;
template class SwapTwoThings<std::string>;

