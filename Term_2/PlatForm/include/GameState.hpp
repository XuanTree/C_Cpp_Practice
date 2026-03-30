#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Audio/SoundBuffer.hpp>
#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
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
  sf::Texture g_platformTexture;
  sf::Sprite g_platformSprite;
  
  const float GRAVITY = 400.f;
  const float playerSpeed = 400.f;
  
  float velocityX = 0.f;
  float velocityY = 0.f;
  bool isOnGround = false;
  bool isJumping = false;
  float coyoteTimeCounter = 0.f;
  float jumpBufferCounter = 0.f;
  const float coyoteTime = 0.1f;
  const float jumpBufferTime = 0.1f;
  const float jumpImpulse = -400.f;
  const float jumpHoldMultiplier = 0.5f;
  const float friction = 1.f;
  const float maxDeltaTime = 0.1f; // 最大时间步长，防止玩家因大deltaTime而消失
  sf::SoundBuffer jumpSoundBuffer;
  sf::Sound jumpSound;

  // 设置玩家动画
  int playerFrameCount = 4;
  int playerFrameWidth;
  int playerFrameHeight;
  int currentAnimationFrame;
  float animationTimer;
  const float animationSpeed = 0.1f; // 每帧持续时间
  std::vector<sf::IntRect> playerFrames;

public:
  GameState(Game &game);
  void handleInput() override;
  void update(sf::Time deltaTime) override;
  void draw() override;
};

#endif
