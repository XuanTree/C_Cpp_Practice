#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> names(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> names[i];
    }

    for (int i = 0; i < n; ++i) {
        std::sort(names[i].begin(), names[i].end());
    }

    std::sort(names.begin(), names.end(), std::greater<std::string>());

    for (int i = 0; i < n; ++i) {
        std::cout << names[i] << std::endl;
    }
}