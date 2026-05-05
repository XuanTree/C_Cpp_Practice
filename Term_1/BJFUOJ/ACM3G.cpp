#include <iostream>
int main(){
    int T;
    std:: cin >> T;
    while (T--){
        int n;
        std:: cin >> n;
        int r = n % 11;
        if (r == 0 || r == 2 || r == 4 || r == 6 || r == 8){
            std:: cout << "Muelsyse king!" << std:: endl;
        }
        else {
            std:: cout << "ov0 win!" << std:: endl;
        }
    }
    return 0;
}