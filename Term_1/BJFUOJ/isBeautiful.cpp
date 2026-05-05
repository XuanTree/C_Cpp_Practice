#include <iostream>
#include <string>
#include <algorithm>
#define N 400
using namespace std;
int main(){
    int n;
    string numbers;
    string result[N];
    cin >> n;
    cin.ignore(1024,'\n');
    for(int i = 0;i < n;i++){
        int isBeautful = 1;
        getline(cin,numbers);
        if(numbers.length() == 1){
            result[i] = numbers;
            continue;
        }
        else{
            int k = numbers.length();
            for(int j = 0;j < k;j++){
                if(numbers[j] != numbers[k - 1 -j]){
                    isBeautful = 0;
                    break;
                }
            }
            if(isBeautful){
                result[i] = numbers;
            }
        }
    }
    int _size = result->size();
    for(int i = 0;i < _size;i++){
        cout << result[i] << endl;
    }
    return 0;
}