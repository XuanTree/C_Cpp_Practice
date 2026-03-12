#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#pragma once
#include "Game.hpp"
#include "State.hpp"
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameState : public State {
private:
  Game &g_game;
  sf::Texture g_gameTexture;

  sf::Sprite g_gameBackground;
  sf::Texture g_PlayerTexture;
  sf::Sprite g_playerSprite;
  
  const float GRAVITY = 12.f;
  const float playerSpeed = 8.f;

public:
  GameState(Game &game);
  void handleInput() override;
  void update(sf::Time deltaTime) override;
  void draw() override;
};

#endif
