#ifndef BATTLEAIRNEO_CHICK_HPP
#define BATTLEAIRNEO_CHICK_HPP

#pragma once
#include "GameManager.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "SFML/Graphics.hpp"

using namespace GameEngine;

class Chick : public ResourceManager {
    enum class PlayerStatus {
        MOVING,
        DEAD
    };

    private:
        sf::Texture chickTexture;
        sf::Sprite chickSprite;
        sf::Vector2f position;
        sf::Vector2f velocity;
        const float speed = 100.f;
    public:
        Chick();

        // ResourceManager Functions Override
        void loadTextures() override;
        void loadSprites() override;
        void loadAudio() override;

        // Detailed Player Functions
        void update(sf::Time dt);
        void draw(sf::RenderWindow &window);
        void move(sf::Vector2f direction);
        void setPosition(sf::Vector2f position);
        sf::Vector2f getPosition();
        PlayerStatus getStatus();
        void setStatus(PlayerStatus status);
        void reset();
        void setVelocity(sf::Vector2f velocity);
        sf::Vector2f getVelocity();
        void setSpeed(float speed);
        float getSpeed();

    };

#endif // BATTLEAIRNEO_CHICK_HPP
