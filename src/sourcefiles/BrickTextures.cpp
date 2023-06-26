#include "BrickTextures.hpp"
#include "BrickSetter.hpp"

#include <iostream>

BrickTextures::BrickTextures()
{
    textureGray = createTexture("src/images/Gray-brick.png");
    textureRed = createTexture("src/images/Red-brick.png");
    textureBlue = createTexture("src/images/Blue-brick.png");
    textureOrange = createTexture("src/images/Orange-brick.png");
    textureBlue_sky = createTexture("src/images/Blue_sky-brick.png");
    textureYellow = createTexture("src/images/Yellow-brick.png");
    textureBrown = createTexture("src/images/Brown-brick.png");
    textureGreen = createTexture("src/images/Green-brick.png");
    textureGreen_bright = createTexture("src/images/Green_bright-brick.png");
}

sf::Texture BrickTextures::createTexture(const std::string& path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        throw std::runtime_error("The image fails to load: " + path); // Exit the program if the image fails to load
    }
    return texture;
}

void BrickTextures::setTextureBasedOnColor(const std::tuple<int, std::string, std::string>& element, sf::Sprite& sprite)
{
    std::string color = std::get<1>(element);

    if (color == "Gray") {
        sprite.setTexture(textureGray);
    } else if (color == "Red") {
        sprite.setTexture(textureRed);
    } else if (color == "Blue") {
        sprite.setTexture(textureBlue);
    } else if (color == "Orange") {
        sprite.setTexture(textureOrange);
    } else if (color == "Blue_sky") {
        sprite.setTexture(textureBlue_sky);
    } else if (color == "Yellow") {
        sprite.setTexture(textureYellow);
    } else if (color == "Brown") {
        sprite.setTexture(textureBrown);
    } else if (color == "Green") {
        sprite.setTexture(textureGreen);
    } else if (color == "Green_bright") {
        sprite.setTexture(textureGreen_bright);
    } else if (color == "skip") {
        
    } else if (color == "null") {
        
    } else {
        throw std::runtime_error("The color dont exist: " + color);
    }
}

void BrickTextures::createBrickSprites(std::vector<BrickLevel>& spriteBricks, std::string pos, std::vector<std::tuple<int, std::string, std::string>>& level)
{
    initializeVariables(pos);
    createTupleVector(level);
    sprite.setScale(0.15f, 0.15f);
    generateSpriteBricks(spriteBricks);
}

void BrickTextures::divString()
{
    for (size_t i = 0; i < m_pos.length(); i++) {
        while (isdigit(m_pos[i])) {
            m_tempStr += m_pos[i];
            i++;
        }
        m_vecDivStr.push_back(m_tempStr);
        m_tempStr = "";
    }
}

void BrickTextures::initializeVariables(std::string pos)
{
    m_pos = pos;
    divString();
    firstX = stof(m_vecDivStr[0]);
    firstY = stof(m_vecDivStr[1]);
    x = firstX;
    y = firstY;
}

void BrickTextures::createTupleVector(std::vector<std::tuple<int, std::string, std::string>>& level)
{
    myVectorTuple.clear();
    myVectorTuple = level;
}

void BrickTextures::generateSpriteBricks(std::vector<BrickLevel>& spriteBricks)
{
    int counter = -1;
    std::cout << "myVectorTuple.size(): " << myVectorTuple.size() << "\n";
    for (size_t i = 0; i < myVectorTuple.size(); i++) {
        std::tuple<int, std::string, std::string> element1 = myVectorTuple.at(i);
        setTextureBasedOnColor(element1, sprite);
        for (int j = 0; j < std::get<0>(element1); j++) {
            if (j == 0) {
                y = firstY + (++counter * (sprite.getGlobalBounds().height + 2.f));
            }
            if (std::get<2>(element1) == "]") {
                if (j == 0) {
                    x = firstX;
                }
            }

            // Skip row if "skip" is encountered
            if (std::get<1>(element1) == "skip") {
                break;
            }
            
            // Double row if "double_Row" is encountered
            if (std::get<2>(element1) == "[[") {
                std::tuple<int, std::string, std::string> element_1 = myVectorTuple.at(++i);
                setTextureBasedOnColor(element_1, sprite);
                for (int j = 0; j < std::get<0>(element_1); j++) {
                    if (j == 0) {
                        x = firstX;
                    }
                    sprite.setPosition(x, y);
                    spriteBricks.push_back({std::get<1>(element_1), sprite});
                    if (std::get<2>(element_1) == "]") {
                        x += sprite.getGlobalBounds().width + 2.f;
                    } else {
                        y += sprite.getGlobalBounds().height + 2.f;
                    }
                }
                std::tuple<int, std::string, std::string> element_2 = myVectorTuple.at(++i);
                setTextureBasedOnColor(element_2, sprite);
                for (int j = 0; j < std::get<0>(element_2); j++) {
                    sprite.setPosition(x, y);
                    spriteBricks.push_back({std::get<1>(element_2), sprite});
                    if (std::get<2>(element_2) == "]") {
                        x += sprite.getGlobalBounds().width + 2.f;
                    } else {
                        y += sprite.getGlobalBounds().height + 2.f;
                    }
                }
                break;
            }


            sprite.setPosition(x, y);
            spriteBricks.push_back({std::get<1>(element1), sprite});
            if (std::get<2>(element1) == "]") {
                x += sprite.getGlobalBounds().width + 2.f;
            } else {
                y += sprite.getGlobalBounds().height + 2.f;
            }
        }
        if (std::get<2>(element1) == "]") {
            y = firstY;
            x = firstX;
        } else {
            y = firstY;
            x += sprite.getGlobalBounds().width + 2.f;
        }
    }
    BrickSetter::getInstance()->setBricks(spriteBricks);
}
