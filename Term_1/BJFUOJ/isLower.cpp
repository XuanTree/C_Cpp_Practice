#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string sentence;
    cin >> sentence;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (islower(sentence[i])) {
            if (!first) {
                cout << "\\";
            } else {
                first = false;
            }
            cout << int(sentence[i]);
        }
    }
    return 0;
}