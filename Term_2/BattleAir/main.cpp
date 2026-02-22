#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sprites.h"
#include "EnemySet.h"
enum GameState{
    GamePlaying,
    GameOver
};
int main(){
    //scores
    int scores = 0;

    //Set the window
    GameState gameState = GamePlaying;
    const float width = 600.0f;
    const float height = 1000.0f;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width,height)), "Battle Air",sf::Style::Titlebar | sf::Style::Close);
    sf::Image icon;
    if(!icon.loadFromFile("assets\\PlayerPlane.png")){
        std::cerr << "The file can not be loaded!" << std::endl;
        return -1;
    }
    window.setIcon(icon);
    sf::Font font("assets\\JetBrainsMono-Regular.ttf");
    sf::Text text(font);text.setString("Game Over!");
    text.setCharacterSize(50);text.setPosition({150.f,height/2});
    text.setFillColor(sf::Color::Red);
    window.setFramerateLimit(60);
    
    //set the ammo
    Ammo::Init();
    std::vector<Ammo> ammos;
    std::vector<Ammo> enemyAmmos;
    sf::Clock shootClock;
    float shootTime = 0.5f;

    //set the enemies
    Enemy::Init();
    std::vector<Enemy> enemy;
    sf::Clock enemySpawnClock;
    float enemySpawnTime = GenRandomTime();

    //set the sound effects
    sf::SoundBuffer shootSoundBuffer;
    sf::SoundBuffer defeatSoundBuffer;
    if(!shootSoundBuffer.loadFromFile("assets\\shoot.mp3")){
        std::cerr << "Sound effect failed to load!" << std::endl;
        return -1;
    }
    if(!defeatSoundBuffer.loadFromFile("assets\\explosion.mp3")){
        std::cerr << "Sound effect failed to load!" << std::endl;
        return -1;
    }
    sf::Sound shootSound(shootSoundBuffer);
    sf::Sound defeatSound(defeatSoundBuffer);

    //set Texture
    auto backgroundSprite = RenderBackground();
    auto playerSprite = RenderPlayer(width,height);

    //Set Speed
    const float moveSpeed = 8.6f;
 
    while (window.isOpen()){
        while (auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if(gameState == GamePlaying){
            if(enemySpawnClock.getElapsedTime().asSeconds() > enemySpawnTime){
                enemy.emplace_back(sf::Vector2f(GenRandomPos(),-50.f));
                enemySpawnClock.restart();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
                playerSprite.move(sf::Vector2f(0.f,-moveSpeed));
            }   
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                playerSprite.move(sf::Vector2f(0.f,moveSpeed));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                playerSprite.move(sf::Vector2f(-moveSpeed,0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                playerSprite.move(sf::Vector2f(moveSpeed,0.f));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
                if(shootClock.getElapsedTime().asSeconds() > shootTime){
                    sf::Vector2f playerPosition = playerSprite.getPosition();
                    ammos.emplace_back(playerPosition,"player");
                    shootSound.play();
                    shootClock.restart();
                }
            }

            //Render
            window.clear();
        
            //Draw
            window.draw(backgroundSprite);
            window.draw(playerSprite);

            for(auto& ammo : ammos){
            ammo.Update("player",10.f);
            }
            for(auto& ammo : enemyAmmos){
                ammo.Update("enemy",10.f);
            }
            for(auto& ene : enemy){
                ene.Update();
            }
            for(auto& ammo : ammos){
                window.draw(ammo);
            }
            for(auto& ammo : enemyAmmos){
                window.draw(ammo);
            }
            for(auto& ene : enemy){
                window.draw(ene);
                ene.Shoot(enemyAmmos,ene.getPosition());
            }
            //ɾ����Ļ����ӵ�
            for(auto it = ammos.begin(); it != ammos.end(); ){
                if(it->getPosition().y < -100.f || it->getPosition().y > height){
                    it = ammos.erase(it); // Erase and update iterator
                    defeatSound.play();
                    scores++;
                }
                else{
                    ++it; // Update iterator if not erasing
                }
            }
            //remove the enemy's ammo that goes out of screen
            for(auto it = enemyAmmos.begin(); it != enemyAmmos.end(); ){
                if(it->getPosition().y < -100.f || it->getPosition().y > height){
                    it = enemyAmmos.erase(it);
                }
                else{
                    ++it;
                }
            }

            //Destroy the enemy
            for(auto it = enemy.begin();it != enemy.end(); ){
                bool hit = false;
                for(auto& ammo : ammos){
                    if(ammo.getGlobalBounds().findIntersection(it->getGlobalBounds())){
                        it = enemy.erase(it);
                        hit = true;
                        break;
                    }
                }
                if(!hit){
                    ++it;
                }
            }
            for(auto& ammo : enemyAmmos){
                if(ammo.getGlobalBounds().findIntersection(playerSprite.getGlobalBounds())){
                    gameState = GameOver;
                }
            }

            //remove the enemy that goes out of screen
            for(auto it = enemy.begin();it != enemy.end(); ){
                if(it->getPosition().y < -100.f || it->getPosition().y > height){
                        it = enemy.erase(it);
                    }
                else{
                    ++it;
                }
            }
        }
        else if(gameState == GameOver){
            std::string scoreStr = std::to_string(scores);
            sf::Text finalScore(font);finalScore.setString("Your score: " + scoreStr);
            finalScore.setCharacterSize(35);finalScore.setPosition({161.f,height/3});
            window.clear(sf::Color::Black);
            window.draw(text);
            window.draw(finalScore);
            window.display();
            defeatSound.play();
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            goto end;
            return 0;
        }
        window.display(); // Display everything on screen
    }
    end:   
    return 0;
}