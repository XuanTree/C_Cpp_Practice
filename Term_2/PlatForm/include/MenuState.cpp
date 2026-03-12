#include "MenuState.hpp"
#include "GameState.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>

MenuState::MenuState(Game& game)
    : m_game(game),
      m_background(game.resources.getTexture("menuBg")),
      m_title(game.resources.getFont("main"), "Platform Jumping", 50),
      m_PlayButton(game.resources.getFont("main"), "Play", 50),
      m_ExitButton(game.resources.getFont("main"), "Exit", 50)
{
    // 背景适应图片大小
    sf::Vector2u winSize = game.getWindow().getSize();
    sf::Vector2u texSize = m_background.getTexture().getSize();

    // 设置标题位置
    sf::FloatRect titleBounds = m_title.getLocalBounds();
    m_title.setOrigin(titleBounds.getCenter());
    m_title.setPosition({ winSize.x / 2.f, 150.f });
    m_title.setFillColor(sf::Color::White);

    // 设置 Play 按钮
    sf::FloatRect playBounds = m_PlayButton.getLocalBounds();
    m_PlayButton.setOrigin(playBounds.getCenter());
    m_PlayButton.setPosition({ winSize.x / 2.f, 300.f });
    m_PlayButton.setFillColor(sf::Color::White);

    // 设置 Exit 按钮
    sf::FloatRect exitBounds = m_ExitButton.getLocalBounds();
    m_ExitButton.setOrigin(exitBounds.getCenter());
    m_ExitButton.setPosition({ winSize.x / 2.f, 400.f });
    m_ExitButton.setFillColor(sf::Color::White);
}

void MenuState::handleInput() {
    auto& window = m_game.getWindow();

    sf::FloatRect exitBounds = m_ExitButton.getGlobalBounds();
    sf::FloatRect playBounds = m_PlayButton.getGlobalBounds();

    while (auto event = m_game.getWindow().pollEvent()) {
        if (event->is<sf::Event::Closed>()){
            m_game.getWindow().close();
        } else if (auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                 sf::Vector2f clickPos(mouseButtonPressed->position.x, mouseButtonPressed->position.y);
                      if (exitBounds.contains(clickPos)) {
                          window.close();
                      } else if (playBounds.contains(clickPos)) {
                          m_game.changeState(std::make_unique<GameState>(m_game));
                      }
            }
        }
    }
}

void MenuState::update(sf::Time /*deltaTime*/) {
    // 菜单界面无需更新逻辑
}

void MenuState::draw() {
    auto& window = m_game.getWindow();
    window.draw(m_background);
    window.draw(m_title);
    window.draw(m_PlayButton);
    window.draw(m_ExitButton);
}