#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count = 0;
    for(char ch:s){
        if(isdigit(ch)){
            count++;
        }
    }
    cout << count;
    return 0;
}