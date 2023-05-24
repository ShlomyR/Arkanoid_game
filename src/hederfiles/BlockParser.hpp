#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>



 struct BrickLevel {
    float x;
    float y;
    std::string color;
    sf::Sprite sprite;
};

class BlockParser
{
public:
    BlockParser() {}
    ~BlockParser() = default;
   
    std::vector<BrickLevel> readLevelFile(int levelNumber);
    bool initSpriteLookup(std::unordered_map<std::string, sf::Texture> &);
    bool readStartPosition(std::ifstream &, float &, float &);
    bool loadSprites(const std::unordered_map<std::string, sf::Texture> &);
    bool parseLines(std::ifstream &, const std::unordered_map<std::string, sf::Texture> &, float, float, std::vector<BrickLevel> &);
private:
    std::unordered_map<std::string, sf::Sprite> m_sprites;
};
