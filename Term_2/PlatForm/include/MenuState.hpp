#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "State.hpp"
#include "Game.hpp"

class MenuState : public State {
private:
    Game& m_game; // 引用游戏实例
    sf::Sprite m_background; // 背景图片
    sf::Text m_title; // 菜单标题
    sf::Text m_PlayButton; // 开始游戏按钮
    sf::Text m_ExitButton; // 退出游戏按钮
    void initText(sf::Text& text, const std::string& str, float y) {
        text.setFont(m_game.resources.getFont("main"));
        text.setString(str);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.getCenter());
        text.setPosition(sf::Vector2f({m_game.getWindow().getSize().x / 2.0f, y}));
    }
public:
    MenuState(Game& game);   // 构造函数，接收 Game 引用
    void handleInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;
};

#endif // MENU_STATE_HPP