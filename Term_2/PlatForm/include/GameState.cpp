#include "GameState.hpp"
#include "Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>

GameState::GameState(Game& game)
    : g_game(game),
    g_gameBackground(game.resources.getTexture("SimpleBg")),
    g_PlayerTexture(game.resources.getTexture("knight")),
    g_playerSprite(g_PlayerTexture),
    g_platformTexture(game.resources.getTexture("PlatformTexture")),
    g_platformSprite(g_platformTexture),
    currentAnimationFrame(0),
    animationTimer(0.f),
    jumpSoundBuffer(game.resources.getSoundBuffer("jump")),
    jumpSound(jumpSoundBuffer)
{
    // 设置背景
    sf::Vector2u winsize = game.getWindow().getSize();

    // 设置平台
    g_platformSprite.setScale({10.f,10.f});
    sf::FloatRect platformRect = g_platformSprite.getLocalBounds();
    g_platformSprite.setOrigin(platformRect.getCenter());
    g_platformSprite.setPosition({winsize.x/2.f,300.f});

    // 设置玩家动画帧
    g_playerSprite.setScale({0.5f,0.5f});
    playerFrameWidth = g_PlayerTexture.getSize().x / playerFrameCount;
    playerFrameHeight = g_PlayerTexture.getSize().y;
    
    playerFrames.clear();
    for (int i = 0; i < playerFrameCount; ++i) {
        playerFrames.emplace_back(sf::Vector2i(i * playerFrameWidth, 0), sf::Vector2i(playerFrameWidth, playerFrameHeight));
    }
    
    g_playerSprite.setTextureRect(playerFrames[0]);

    // 设置玩家初始位置
    sf::FloatRect playerRect = g_playerSprite.getGlobalBounds();
    g_playerSprite.setOrigin(playerRect.getCenter());
    g_playerSprite.setPosition({winsize.x/2.f,150.f});

}

void GameState::handleInput() {
    auto& window = g_game.getWindow();

    while (auto event = g_game.getWindow().pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            g_game.getWindow().close();
        }
        // 这里只处理窗口关闭等事件，移动交给update
    }
}

void GameState::update(sf::Time deltaTime) {
    float dt = deltaTime.asSeconds();
    if (dt > maxDeltaTime) dt = maxDeltaTime;

    animationTimer += dt;
    bool isMoving = false;
    bool isJumpSoundPlayed = false;

    // 更新土狼时间和跳跃缓冲计时器
    if (isOnGround) {
        coyoteTimeCounter = coyoteTime;
    } else {
        coyoteTimeCounter -= dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isJumpSoundPlayed) {
        jumpBufferCounter = jumpBufferTime;
        isJumpSoundPlayed = true;
    } else {
        jumpBufferCounter -= dt;
    }

    if (isJumpSoundPlayed && jumpBufferCounter > 0.f && (isOnGround || coyoteTimeCounter > 0.f)) {
        jumpSound.play();
    }

    // 地面检测：玩家底部与平台顶部相交
    sf::FloatRect playerBounds = g_playerSprite.getGlobalBounds();
    sf::FloatRect platformBounds = g_platformSprite.getGlobalBounds();
    bool wasOnGround = isOnGround;
    // 简单相交检测，实际可能需要更精确的底部检测
    isOnGround = playerBounds.findIntersection(platformBounds).has_value();

    // 如果刚离开地面，启动土狼时间（已在上面处理）
    // 如果刚落地，重置跳跃状态
    if (isOnGround && !wasOnGround) {
        velocityY = 0.f;
        isJumping = false;
    }

    // 水平移动
    velocityX = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        g_playerSprite.setScale({-0.5f,0.5f}); // 向左时水平翻转
        isMoving = true;
        velocityX = -playerSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        g_playerSprite.setScale({0.5f,0.5f}); // 向右时水平翻转
        isMoving = true;
        velocityX = playerSpeed;
    }

    // 动画更新
    if (isMoving) {
        // 根据累积时间计算应推进的帧数
        int framesToAdvance = static_cast<int>(animationTimer / animationSpeed);
        if (framesToAdvance > 0) {
            currentAnimationFrame = (currentAnimationFrame + framesToAdvance) % playerFrames.size();
            animationTimer -= framesToAdvance * animationSpeed;
            g_playerSprite.setTextureRect(playerFrames[currentAnimationFrame]);
        }
    } else {
        // 空闲状态：重置到第一帧，并重置计时器
        currentAnimationFrame = 0;
        animationTimer = 0.f;
        g_playerSprite.setTextureRect(playerFrames[0]);
    }

    // 地面摩擦
    if (isOnGround) {
        velocityX *= friction;
    }

    // 跳跃处理
    if (jumpBufferCounter > 0.f && (isOnGround || coyoteTimeCounter > 0.f)) {
        velocityY = jumpImpulse;
        isJumping = true;
        jumpBufferCounter = 0.f;
        coyoteTimeCounter = 0.f;
    }

    // 可变高度跳跃：如果松开跳跃键且仍在上升，增加重力
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && velocityY < 0.f) {
        velocityY += GRAVITY * dt * jumpHoldMultiplier;
    }

    // 应用重力（仅当不在地面时）
    if (!isOnGround) {
        velocityY += GRAVITY * dt;
    }

    // 更新位置
    g_playerSprite.move({velocityX * dt, velocityY * dt});

    // 防止穿过平台（简单处理）
    // 如果玩家与平台相交且正在下落，则标记为在地面并停止垂直速度
    sf::FloatRect newPlayerBounds = g_playerSprite.getGlobalBounds();
    if (newPlayerBounds.findIntersection(platformBounds) && velocityY > 0.f) {
        // 将玩家置于平台顶部
        float platformTop = platformBounds.position.y;
        float playerBottom = newPlayerBounds.position.y + newPlayerBounds.size.y;
        float overlap = playerBottom - platformTop;
        if (overlap > 0) {
            g_playerSprite.move({0, -overlap});
        }
        velocityY = 0.f;
        isOnGround = true;
        isJumping = false;
    }
}

void GameState::draw() {
    auto& window = g_game.getWindow();
    window.draw(g_gameBackground);
    window.draw(g_playerSprite);
    window.draw(g_platformSprite);
}