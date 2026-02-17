#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprites.h" 
sf::Sprite RenderBackground(){
    static sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("assets\\BattleAirBackGround.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    return backgroundSprite;
}
sf::Sprite RenderPlayer(const float width,const float height){
    static sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("assets\\PlayerPlane.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
    }
    sf::Sprite playerSprite(playerTexture);
    sf::IntRect dir[1];
    dir[0] = sf:: IntRect({0,0},{32,32});
    playerSprite.setTextureRect(dir[0]);
    playerSprite.setOrigin({16,16});
    playerSprite.scale(sf::Vector2f(1.4f,1.4f));
    playerSprite.setPosition({width/2.0f,height/2.0f});
    return playerSprite;
}
//Set the texture of the ammo
sf::Texture Ammo::playerTexture;
sf::Texture Ammo::enemyTexture;

void Ammo::Init(){
    if(!playerTexture.loadFromFile("assets/ammoPlayer.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
        return;
    }
    if(!enemyTexture.loadFromFile("assets/ammoEnemy.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
        return;
    }
}
Ammo::Ammo(sf::Vector2f position,const std::string& entity_type): sf::Sprite(
    entity_type == "player" ? playerTexture : enemyTexture){
        this->entity_type = entity_type;
        this->setOrigin({16,16});
        this->setScale({0.4f,0.4f});
        this->setPosition(position);
}
void Ammo::Update(const std::string& entity_type,const float speed){
    const float direction = (entity_type == "player") ? -1.f : 1.f;
    this->move({0.f,direction * speed});
}

//set the Enemy Plane
sf::Texture Enemy::enemyPlaneTex;

void Enemy::Init(){
    if(!enemyPlaneTex.loadFromFile("assets\\EnemyPlane.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
        return;
    }
}
Enemy::Enemy(sf::Vector2f position,const std::string& entity_type): sf::Sprite(
    enemyPlaneTex){
        this->setOrigin({16,16});
        this->setScale({1.4f,1.4f});
        this->setPosition(position);
}
void Enemy::Update(const std::string& entity_type,const float speed){
    float direction = 1.f;
    this->move({0.f,direction * speed});
}
void Enemy::Shoot(std::vector<Ammo>& ammos,sf::Vector2f position){
    if(enemyShootClock.getElapsedTime().asSeconds() > enemyShootTime){
        ammos.emplace_back(position,"enemy");
        enemyShootClock.restart();
        enemyShootTime = 0.5f + (rand() % 100) / 100.0f;
    }
}