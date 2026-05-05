#include <iostream>
using std:: cout;
using std:: cin;
using std:: endl;
int main(){
    int lines;
    cin >> lines;
    for(int i = 1;i <= lines;i++){
        int length = 1;
        while(i >= length){
            cout << length << "*" << i << "=" << i * length;
            while(i > length){
                cout << " ";
                break;
            }
            length++;
        }
        cout << endl;
    }
    return 0;
}