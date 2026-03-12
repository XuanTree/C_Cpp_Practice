#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <string>

class ResourceManager{
private:
    // 存储贴图
    std::map<std::string, sf::Texture> textures;
    // 存储字体
    std::map<std::string, sf::Font> fonts;
    // 存储声音缓冲
    std::map<std::string, sf::SoundBuffer> soundBuffers;
public:
    ResourceManager() {};
    
    // 加载贴图
    void loadTexture(const std::string& name, const std::string& filename){
        sf::Texture texture;
        if(texture.loadFromFile(filename)){
            textures[name] = texture;
        } else {
            std::cerr << "Failed to load texture: " << filename << std::endl;
        }
    }
    // 获取贴图
    sf::Texture& getTexture(const std::string& name){
        auto it = textures.find(name);
        if (it == textures.end()) {
            std::cerr << "Texture not found: " << name << " returning empty texture." << std::endl;
            textures[name] = sf::Texture();
        }
        return textures.at(name);
    }
    // 加载字体
    void loadFont(const std::string& name, const std::string& filename){
        sf::Font font;
        if(font.openFromFile(filename)){
            fonts[name] = font;
        } else {
            std::cerr << "Failed to load font: " << filename << std::endl;
        }
    }
    // 获取字体
    sf::Font& getFont(const std::string& name){
        auto it = fonts.find(name);
        if (it == fonts.end()) {
            std::cerr << "Font not found: " << name << " returning empty font." << std::endl;
            fonts[name] = sf::Font();
        }
        return fonts.at(name);
    }
};

#endif // RESOURCE_MANAGER_HPP