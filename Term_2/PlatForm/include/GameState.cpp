#include "GameState.hpp"
#include "Game.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

GameState::GameState(Game& game)
    : g_game(game),
    g_gameBackground(game.resources.getTexture("SimpleBg")),
    g_PlayerTexture(game.resources.getTexture("PlayerTexture")),
    g_playerSprite(g_PlayerTexture)
{
    // 设置背景
    sf::Vector2u winsize = game.getWindow().getSize();

}

void GameState::handleInput() {
    auto& window = g_game.getWindow();

    window.setFramerateLimit(120);

    while (auto event = g_game.getWindow().pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            g_game.getWindow().close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            g_playerSprite.move({0,-playerSpeed});
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            g_playerSprite.move({0,playerSpeed});
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            g_playerSprite.move({-playerSpeed,0});
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            g_playerSprite.move({playerSpeed,0});
        }
    }
}

void GameState::update(sf::Time deltaTime) {

}

void GameState::draw() {
    auto& window = g_game.getWindow();
    window.draw(g_gameBackground);
    window.draw(g_playerSprite);
}