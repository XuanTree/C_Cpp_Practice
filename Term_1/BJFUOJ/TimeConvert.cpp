#include <iostream>
int main(){
    int totalSeconds;
    std:: cin >> totalSeconds;
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = (totalSeconds % 3600) % 60;
    std::cout << hours << ":" << minutes << ":" << seconds;
    return 0;
}