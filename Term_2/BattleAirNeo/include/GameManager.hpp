#ifndef BATTLEAIRNEO_GAMEMANAGER_HPP
#define BATTLEAIRNEO_GAMEMANAGER_HPP

namespace GameEngine {
    class GameManager {
        public:
        GameManager() = default;
        virtual ~GameManager() = default;

        virtual bool initialize() = 0;
        virtual void finalize() = 0;
    };

    class ResourceManager : public GameManager {
        public:
        ResourceManager() = delete;

        ~ResourceManager() override = default;

        bool initialize() override = 0;
        void finalize() override = 0;

        // 加载材质和纹理
        virtual void loadTextures() = 0;
        virtual void unloadTextures() = 0;

        // 加载精灵
        virtual void loadSprites() = 0;
        virtual void unloadSprites() = 0;

        // 加载音频
        virtual void loadAudio() = 0;
        virtual void unloadAudio() = 0;
    };

    class SceneManager : public GameManager {
        public:
        SceneManager() = delete;

        ~SceneManager() override = default;
        
        enum class GameStatus {
            INIT,
            RUNNING,
            PAUSED,
            GAMEOVER
        };

        bool initialize() override = 0;
        void finalize() override = 0;

        // 加载场景
        virtual void loadScene() = 0;
        virtual void unloadScene() = 0;

        // 更新场景
        virtual void updateScene() = 0;

        // 渲染场景
        virtual void renderScene() = 0;
    };
}

#endif //BATTLEAIRNEO_GAMEMANAGER_HPP
