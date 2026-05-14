#include <iostream>
#include "string.hpp"

int main() {

    const string content = "Hello World";
    const string content2 = " From Custom String Messages! ";

    string new_content = content + content2;

    std::cout << new_content << std::endl;
    return 0;
}