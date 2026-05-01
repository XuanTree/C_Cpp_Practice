#include <iostream>
#include "Test.hpp"

int main() {
	std::cout << "Hello Cmake From Visual Studio !" << std::endl;

	Test test(64);

	test.print();
	return 0;
}