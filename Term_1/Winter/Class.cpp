#include <cstdio>
#include <iostream>
#include <random>
class Player{
    private:
        std:: string name;
    public:
        int damage;    
        int hp;    
        int Attack(class Player player){
            player.hp -= damage;
            return player.hp;
        }
    Player(std:: string name,int hp,int damage) : name(name),hp(hp),damage(damage){};
};
int GenRandDamage(){
    std:: random_device rd;
    std:: mt19937 gen(rd());
    std:: uniform_int_distribution<> dis(1,90);
    return dis(gen);
}
int main(){
    int hp_1,hp_2,damage_1,damage_2;

    std:: cout << "Welcome to the Game!" << std:: endl
        << "Now enter the first player's hp:";
    std:: cin >> hp_1;
    std:: cout << "Great!Now enter the second player's hp to start the game!" << std:: endl;
    std:: cin >> hp_2;

    damage_1 = GenRandDamage();
    damage_2 = GenRandDamage();

    Player player1("Player1",hp_1,damage_1);
    Player player2("Player2",hp_2,damage_2);

    while(1){
        if(player1.hp <= 0){
            std:: cout << "Player1 Lose!!!" << std:: endl;
            break;
        }
        else if(player2.hp <= 0){
            std:: cout << "Player2 Lose!!!" << std:: endl;
            break;
        }
        player2.hp = player1.Attack(player2);
        player1.hp = player2.Attack(player1);
        
        if(player1.damage > 45){
            std:: cout << "Wow for Player1!!!" << std:: endl;
        }
        else if(player2.damage > 45){
            std:: cout << "Wow for Player2!!!" << std:: endl;
        }
        
        std:: cout << "Player1 does " << damage_1 << " damage!" << std:: endl;
        std:: cout << "Player2 does " << damage_2 << " damage!" << std:: endl;

        player1.damage = GenRandDamage();
        player2.damage = GenRandDamage();
    }
    std:: cout << std:: endl << "The Game Ends!!!" << std:: endl;
    system("pause");
    return 0;
}