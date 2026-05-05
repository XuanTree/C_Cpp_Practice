#include <iostream>
#include <string>
using namespace std;
int main(){
    string planet;
    string team_name;
    cin >> planet >> team_name; 
    int planet_result = 1;
    int team_name_result = 1;
    for(int i = 0;i < planet.length();i++){
        int num = planet[i] - 64;
        planet_result *= num;
    }
    for(int i = 0;i < team_name.length();i++){
        int num = team_name[i] - 64;
        team_name_result *= num;
    }
    if(planet_result % 47 == team_name_result % 47){
        cout << "GO";
    }
    else{
        cout << "STAY";
    }
    return 0;
}