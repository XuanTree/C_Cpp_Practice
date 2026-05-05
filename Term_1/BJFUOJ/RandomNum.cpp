#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}