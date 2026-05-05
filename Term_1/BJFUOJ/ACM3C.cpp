#include <iostream>
#include <vector>
using namespace std;
int gcd(int num1,int num2){
    while(num2 != 0){
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main(){
    vector<int> mana;
    int n;
    cin >> n;
    while(n--){
        int herb;
        cin >> herb;
        if(herb <= 0){
            continue;
        }
        else{
            mana.push_back(herb);
        }
    }
    if(mana.size() == 1){
        cout << mana[0];
    }
    if(mana.size() == 2){
        cout << gcd(mana[0],mana[1]);
    }
    else{
        int m = gcd(mana[0],mana[1]);
        for(int i = 2;i < mana.size();i++){
            m = gcd(m,mana[i]);
        }
        cout << m;
    }
    return 0;
}