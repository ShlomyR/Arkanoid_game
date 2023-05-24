#pragma once

#include "Rectangle.hpp"
#include "BrickType.hpp"
#include "BlockParser.hpp"

class GameState;

#include <vector>
#include <thread>

class Brick : public Rectangle
{
public:
    explicit Brick(const sf::Vector2f &, const sf::Vector2f &, const sf::Color &, GameState &);
    ~Brick() = default;

    void move(float, float) override;
    void setPosition(float, float) override;
    void draw(sf::RenderWindow &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;
    
    std::vector<std::vector<BrickLevel>> getVecBricks();
    std::unique_ptr<sf::RectangleShape> &getShape();
    BrickLevel getBrick(int);
    BrickColor getColor() const;
    int const& getCurrLevel();
    std::vector<bool> &getVecLevels();

    void initializeLevels(int endLevel);

    void deleteBrick(int);

    bool isEmpty();

    void setCurrLevel(int val);

    void deleteAllBricks();


private:
    Brick(Brick const& other) = delete;
    Brick operator=(Brick const& other) = delete;

    void init(const std::vector<BrickLevel> &);
private:
    std::vector<BrickLevel> m_bricks;
    std::vector<std::vector<BrickLevel>> m_levels;

    std::unique_ptr<sf::RectangleShape> m_shape;
    std::vector<sf::Vector2i> m_hitBricks;

    GameState &m_gameState;
    BlockParser m_blockParser;
    
    BrickColor m_color;
    
    bool m_isDestroyed;
    int m_currentLevel;
};