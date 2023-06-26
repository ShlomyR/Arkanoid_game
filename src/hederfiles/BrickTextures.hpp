#pragma once

#include "BrickType.hpp"

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <vector>
#include <string>
#include <tuple>

class BrickTextures
{
public:
    BrickTextures();

    sf::Texture createTexture(const std::string&);
    void setTextureBasedOnColor(const std::tuple<int, std::string, std::string>&, sf::Sprite&);
    void createBrickSprites(std::vector<BrickLevel>&, std::string, std::vector<std::tuple<int, std::string, std::string>>&);
private:
    void initializeVariables(std::string);
    void createTupleVector(std::vector<std::tuple<int, std::string, std::string>>&);
    void generateSpriteBricks(std::vector<BrickLevel>&);
    void divString();
private:
    sf::Texture textureGray;
    sf::Texture textureRed;
    sf::Texture textureBlue;
    sf::Texture textureOrange;
    sf::Texture textureBlue_sky;
    sf::Texture textureYellow;
    sf::Texture textureBrown;
    sf::Texture textureGreen;
    sf::Texture textureGreen_bright;
    float firstX;
    float firstY;
    float x;
    float y;
    std::string m_pos;
    std::string m_tempStr;
    std::vector<std::string> m_vecDivStr;
    std::vector<std::tuple<int, std::string, std::string>> myVectorTuple;
    std::tuple<int, std::string, std::string> myTuple;
    sf::Sprite sprite;
};
