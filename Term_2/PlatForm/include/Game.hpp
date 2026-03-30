#pragma once
#include "ResourceManager.hpp"
#include "State.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <stack>

class Game {
private:
  sf::RenderWindow window;

  std::stack<std::unique_ptr<State>> states; // 状态栈，使用智能指针管理内存
  // 延迟的状态替换（在当前帧结束后执行，避免在状态方法内销毁自身）
  std::unique_ptr<State> pendingState;
  bool pendingReplace = false;
public:
  ResourceManager resources; // 资源管理器实

  Game() {
    window.create(sf::VideoMode({800, 600}), "Platform Jumping");
    window.setVerticalSyncEnabled(true);
  }
  void pushState(std::unique_ptr<State> state) {
    states.push(std::move(state));
  }
  void popState() {
    if (!states.empty()) {
      states.pop();
    }
  }
  // 请求在当前帧结束后替换顶层状态（安全，避免在状态成员函数内销毁自身）
  void changeState(std::unique_ptr<State> state) {
    pendingState = std::move(state);
    pendingReplace = true;
  }
  void run() {
    sf::Clock clock;
    sf::Image icon;
    if (!icon.loadFromFile("assets\\sprites\\icon.png")) {
      std::cout << "icon load failed!" << std::endl;
    } else {
      window.setIcon(icon);
    }
    while (window.isOpen()) {
      sf::Time deltaTime = clock.restart();
      if (!states.empty()) {
        states.top()->handleInput();
        states.top()->update(deltaTime);
        window.clear();
        states.top()->draw();
        window.display();
        // 在一帧结束后再执行替换，保证不会在状态自身方法中销毁该对象
        if (pendingReplace) {
          if (!states.empty()) {
            states.pop();
          }
          if (pendingState) {
            states.push(std::move(pendingState));
          }
          pendingReplace = false;
        }
      } else {
        window.close();
      }
    }
  }
  sf::RenderWindow &getWindow() { return window; }
};
