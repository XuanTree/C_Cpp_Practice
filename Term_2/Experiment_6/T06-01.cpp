#include <algorithm>
#include <iostream>

int main() {
    std::string input;
    std::cin >> input;

    std::sort(input.begin(), input.end(), std::greater<char>());

    std::cout << input << std::endl;
    return 0;
}