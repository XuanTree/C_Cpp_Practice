#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
typedef struct Character{
    double player_health;
    double player_defense;
    double player_damage;
    double enemy_health;
    double enemy_defense;
    double enemy_damage;
}Character;
Character characterSet(double cha1_h,double cha1_d,double cha1_a){
    Character ch;
    srand(time(NULL));
    ch.enemy_damage = rand() % 100 + 1;
    ch.enemy_defense = rand() % 10 + 1;
    ch.enemy_health = rand() % 100000 + 1;
    ch.player_damage = cha1_a;
    ch.player_defense = cha1_d;
    ch.player_health = cha1_h;
    printf("    Player Data | Enemy Data\n");
    printf("------------------------------\n");
    printf(" HP:\t %.2lf | %.2lf \n",cha1_h,ch.enemy_health);
    printf("------------------------------\n");
    printf(" defense:%.2lf | %.2lf \n",cha1_d,ch.enemy_defense);
    printf("------------------------------\n");
    printf(" Damage: %.2lf | %.2lf \n",cha1_a,ch.enemy_damage);
    printf("------------------------------\n");
    return ch;
}
Character playerRound(Character ch,double player_damage){
    ch.enemy_health = ch.enemy_health + ch.enemy_defense - player_damage;
    return ch;
}
Character enemyRound(Character ch,double enemy_damage){
    ch.player_health = ch.player_health + ch.player_defense - enemy_damage;
    return ch;
}
void Divider(){
    printf("\n");
    printf("--------------------");
    printf("\n");
    return;
}
void showInfo(double playerHP,double enemyHP){
    Divider();
    printf("\nYour HP is %.2lf\tEnemy HP is %.2lf !\n",playerHP,enemyHP);
    return;
}
int main(){
    int turn = 1;
    double player_health;
    double player_defense;
    double player_damage;
    Character(*p_characterSet)(double,double,double);
    p_characterSet = &characterSet;
    printf("Welcome to the C Console Game!\n");
    printf("Input your data(HP Defense Damage):");
    scanf("%lf %lf %lf",&player_health,&player_defense,&player_damage);
    Character ch = p_characterSet(player_health,player_defense,player_damage);
    while(1){
        printf("\n--TURN %d--\n",turn);
        ++turn;
        ch = playerRound(ch, ch.player_damage);
        if(ch.enemy_health <= 0){
            printf("Enemy is defeated! You won!\n");
            break;
        }
        ch = enemyRound(ch, ch.enemy_damage);
        if(ch.player_health <= 0){
            printf("You have no HP. You lost!\n");
            break;
        }
        sleep(1);
        showInfo(ch.player_health, ch.enemy_health);
        Divider();
    }
    return 0;
}