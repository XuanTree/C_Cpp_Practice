#include <iostream>

using namespace std;

template<typename T>
void Input(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }
}

template<typename T>
void Sort(T arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void Output(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int main() {
    const int LEN = 5;
    int type;
    while (std::cin >> type) {
        switch (type) {
            case 0: 
            {
                int a1[LEN];
                Input<int>(a1, LEN); Sort<int>(a1, LEN); Output<int>(a1, LEN);
                break;
            }
            case 1: 
            {
                char a2[LEN];
                Input(a2, LEN); Sort(a2, LEN); Output(a2, LEN); 
                break; 
            }
            case 2: 
            {
                double a3[LEN];
                Input(a3, LEN); Sort(a3, LEN); Output(a3, LEN);
                break;
            }
        }
    }

    return 0;
}