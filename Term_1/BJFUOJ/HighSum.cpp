#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string Sum(string A,string B){
    vector<int> a,b,res;
    //字符串转Vector(低位在前)
    for(int i = A.size() - 1;i >= 0;i--){
        a.push_back(A[i] - '0');
    }
    for(int i = B.size() - 1;i >= 0;i--){
        b.push_back(B[i] - '0');
    }
    int carry = 0;//进位
    for(int i = 0;i < a.size() || i < b.size() || carry;i++){
        int sum = carry;
        if(i < a.size()){
            sum += a[i];
        }
        if(i < b.size()){
            sum += b[i];
        }
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    string ans;//vector转字符串,并反转字符.
    for(int i = res.size() - 1;i >= 0;i--){
        ans += (res[i] + '0');
    }
    return ans;
}
int main(){
    string a,b;
    cin >> a >> b;
    cout << Sum(a,b);
    return 0;
}