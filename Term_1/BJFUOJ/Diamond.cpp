#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int spaces, stars;
        if(i <= n/2 + 1) {
            spaces = (n/2 + 1) - i;
            stars = 2 * i - 1;
        } else {
            spaces = i - (n/2 + 1);
            stars = 2 * (n - i + 1) - 1;
        }
        for(int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for(int k = 0; k < stars; k++) {
            cout << "*";
        }
        cout << endl;
    }
}