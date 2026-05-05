#include <iostream>
#include "Test.hpp"
#include "Student.hpp"

int main() {
    std::cout << "Hello Cmake From Visual Studio !" << std::endl;

    const Test test(64);

    test.print();

    const PrintThings<std::string> printThings("Hello Message From Templates!");

    printThings.Print();

    Student Jack("Jack", 18);

    Jack.PrintMessages();
    Jack.SayHi();
    Jack.ChangeTheJob("Worker");
    Jack.PrintMessages();

    std::string hello = "Hello";
    std::string world = "World";

    SwapTwoThings<std::string> swap(hello, world);

    swap.Swap();

    return 0;
}