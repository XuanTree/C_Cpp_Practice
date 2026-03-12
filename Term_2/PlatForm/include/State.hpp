#ifndef STATE_HPP
#define STATE_HPP

#pragma once
#include <SFML/Graphics.hpp>

// 创建基本接口
class State{
public:
    virtual ~State() {}
    //处理输入
    virtual void handleInput() = 0;
    //更新游戏逻辑
    virtual void update(sf::Time deltaTime) = 0;
    //渲染游戏
    virtual void draw() = 0;
};

#endif // STATE_HPP