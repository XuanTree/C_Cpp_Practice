#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string pwd;
    cin >> n >> pwd;
    for(int i = 0;i < pwd.length();i++){
        int num = int(pwd[i]) + n;
        if(num <= 122){
            cout << char(num);
        }
        else{
            int newNum = num - 123 + 97;
            cout << char(newNum);
        }
    }
    return 0;
}