#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int amount = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            amount += pow(2,i);
        }
        cout << amount << endl;
    }
    return 0;
}