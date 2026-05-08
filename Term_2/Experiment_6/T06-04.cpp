#include <iostream>
#include <queue>

int main() {
    int n;

    std::cin >> n;

    std::queue<int> cards;

    for (int i = 0; i < n; i++) {
        cards.push(i + 1);
    }

    for (int i = 0; i < n; i++ ){
        std::cout << cards.front() << " ";
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    return 0;
}