#include <iostream>
#include <iomanip>
using std:: cout;
using std:: cin;
using std:: endl;
using std:: fixed;
using std:: setprecision;
int main(){
    int count;
    while(cin >> count){
        double array[count];
        for(int i = 0;i < count;i++){
            cin >> array[i];
        }
        for(int i = 0;i <count;i++){
            if(array[i] >= 30){
                if(array[i] < 50){
                    cout << fixed << setprecision(2) << array[i] - 5.00 << endl;
                }
                else{
                    if(array[i] < 100){
                        cout << fixed << setprecision(2) << array[i] * 0.90 << endl;
                    }
                    else{
                        cout << fixed << setprecision(2) << array[i] * 0.80 << endl;
                    }
                }
            }
            else{
                cout << fixed << setprecision(2) << array[i] << endl;
            }
        }
    }
    return 0;
}