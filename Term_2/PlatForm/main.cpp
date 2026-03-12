#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include "include/MenuState.hpp"

int main() {
    Game game;

    // 加载资源（字体和背景纹理）
    game.resources.loadFont("main", "assets/fonts/main.ttf");
    game.resources.loadTexture("menuBg", "assets/sprites/SimpleBg.png");
    // 预加载玩家贴图，避免切换到 GameState 时找不到资源导致异常
    game.resources.loadTexture("SimpleBg", "assets/sprites/SimpleBg.png");
    game.resources.loadTexture("PlayerTexture", "assets/sprites/PlayerTexture.png");

    // 创建菜单状态并推入栈
    game.pushState(std::make_unique<MenuState>(game));

    // 运行游戏主循
    game.run();
    
    return 0;
}
