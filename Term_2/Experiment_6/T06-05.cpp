#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {

    int N, Q;

    while(std::cin >> N >> Q) {

        std::vector<int> numbers(N);
        std::vector<int> questions(Q);

        for (int i = 0; i < N; i++) {
            std::cin >> numbers[i];
        }
        for (int i = 0; i < Q; i++) {
            std::cin >> questions[i];
        }

        std::sort(numbers.begin(), numbers.end());

        for (int i = 0; i < Q; ++i) {
            std::vector<int>::iterator it = std::lower_bound(numbers.begin(), numbers.end(), questions[i]);
            if (it != numbers.end() && *it == questions[i]) {
                std::cout << questions[i] << " found at " << std::distance(numbers.begin(), it) + 1 << std::endl;
            } else {
                std::cout << questions[i] << " not found " << std::endl; // not found 后面需要空格！！！
            }
        }
    }

    return 0;
}