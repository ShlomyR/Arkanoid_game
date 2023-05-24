#include "../hederfiles/Parser_1.hpp"

std::vector<BrickLevel> Parser::readLevelFile(int levelNumber)
{
    std::vector<BrickLevel> bricks;

    std::string filename = "src/levels/level-" + std::to_string(levelNumber) + ".dat";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return bricks;
    }

    static std::unordered_map<std::string, sf::Texture> spriteLookup;
    if (!initSpriteLookup(spriteLookup)) {
        return bricks;
    }

    float startX, startY;
    if (!readStartPosition(file, startX, startY)) {
        return bricks;
    }

    if (!parseLines(file, spriteLookup, startX, startY, bricks)) {
        return bricks;
    }

    return bricks;
}

bool Parser::initSpriteLookup(std::unordered_map<std::string, sf::Texture>& spriteLookup)
{
    static const std::vector<std::string> spriteNames {
        "Red", "Green", "Yellow", "Blue", "Blue_sky",
        "Brown", "Gray", "Orange", "Purple"
    };

    for (const auto& spriteName : spriteNames) {
        sf::Texture texture;
        if (!texture.loadFromFile("src/images/" + spriteName + "-brick.png")) {
            std::cerr << "Failed to load texture: " << spriteName << std::endl;
            return false;
        }
        spriteLookup[spriteName] = texture;
    }
    

    return true;
}

bool Parser::readStartPosition(std::ifstream& file, float& startX, float& startY)
{
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Failed to read starting position" << std::endl;
        return false;
    }

    char comma;
    std::string pos;
    if (!(std::istringstream(line) >> pos >> startX >> comma >> startY)) {
        std::cerr << "Failed to parse starting position: " << line << std::endl;
        return false;
    }
    return true;
}

bool Parser::parseLines(std::ifstream& file, const std::unordered_map<std::string, sf::Texture>& spriteLookup,
                        float startX, float startY, std::vector<BrickLevel>& bricks)
{
    std::string line;
    float x = startX;
    float y = startY;
    int counter = -1;
    while (std::getline(file, line)) {
        int numBricks;
        std::string colorStr;
        char Bracket;
        std::istringstream iss(line);
        if (!(iss >> numBricks >> colorStr >> Bracket)) {
            std::cerr << "Failed to parse line: " << line << std::endl;
            continue;
        }

        auto spriteIt = spriteLookup.find(colorStr);
        std::string brickColor = "";
        if (spriteIt == spriteLookup.end()) {
            std::cerr << "Unknown color: " << colorStr << std::endl;
            continue;
        } else {
            brickColor = spriteIt->first;
            //std::cout << brickColor << "\n";
        }
        sf::Sprite sprite(spriteIt->second);
        sprite.setScale(0.15f, 0.15f);
        for (int i = 0; i < numBricks; i++) {
            if (i == 0) {
                y = startY + (++counter*(sprite.getGlobalBounds().height + 2.f));
            }
            if (Bracket == ']') {
                if (i == 0) {
                    x = startX;
                }
            }
            sprite.setPosition(x, y);
            bricks.push_back({x, y, brickColor, sprite});
            if (Bracket == '[') {
                y += sprite.getGlobalBounds().height + 2.f;
            } else {
                x += sprite.getGlobalBounds().width + 2.f;
            }
        }
        if (Bracket == '[') {
            y = startY;
            x += sprite.getGlobalBounds().width + 2.f;
        }
    }

    return true;
}
