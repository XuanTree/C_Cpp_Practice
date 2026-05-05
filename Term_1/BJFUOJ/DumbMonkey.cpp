#include <iostream>
using namespace std;
int FindMax(int num[]){
    int max = 1;
    for(int i = 0; i < 26; i++){
        if(num[i] > max){
            max = num[i];
        }
    }
    return max;
}
int FindMin(int num[]){
    int min = 1000;
    for(int i = 0; i < 26; i++){
        if(num[i] == 0){
            continue;
        }
        else if(num[i] < min){
            min = num[i];
        }
    }
    return min;
}
int isPrime(int num){
    if(num < 2){
        return 0;
    }
    if(num == 2){
        return 1;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    string words;
    cin >> words;
    int frequency[26] = {0};
    for(char c : words){
        frequency[c - 'a']++;
    }
    int max = FindMax(frequency);
    int min = FindMin(frequency);
    int result = max - min;
    if(isPrime(result)){
        cout << "Lucky Word" << endl;
        cout << result << endl;
    }
    else{
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}