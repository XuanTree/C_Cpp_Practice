#include <iostream>
using namespace std;
long long combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    return result;
}
int main(){
    int numRows;
    cin >> numRows;
    if(numRows == 1 || numRows == 2){
        if(numRows == 1){
            cout << "[1]";
        }
        else{
            cout << "[1 1]";
        }
    }
    else{
        for(int i=0;i<numRows;i++){
            cout << '[';
            for(int j=0;j<i+1;j++){
                if(j > 0){
                    cout << " ";
                }
                cout << combination(i,j);
            }
            cout << ']' <<endl;
        }
    }
    return 0;
}