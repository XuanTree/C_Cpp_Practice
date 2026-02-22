#include <iostream>
#include <random>
//Namespace = provides a solution for preventing name conflicts
//            in large projects. Each entity needs a unique name.
//            A namespace allows for identically named entities
//            as long as the namespaces are different.
namespace first{
    int x = 2;
}
namespace second{
    int x = 3;
}
//Using Random Device mt19937 to generate random numbers?
int main(){
    std:: random_device rd;
    int x = 1;
    int win_times = 0;
    bool isLose = false;
    
    while(!isLose){
        int answer;
        std:: mt19937 gen(rd());
        std:: uniform_int_distribution<> dis(0,x);
        std:: cout << "Guess The Number:";
        std:: cin >> answer;
        int rdNum = dis(gen);
        if(answer == rdNum){
            std:: cout << "Correct!" << std:: endl;
            x += 10;
            win_times++;
        }
        else{
            std:: cout << "Oops!" << std:: endl;
            isLose = !isLose;
        }
    }
    std:: cout << "You have won " << win_times << " times!" << std:: endl;

    //system("pause");
    return 0;
}