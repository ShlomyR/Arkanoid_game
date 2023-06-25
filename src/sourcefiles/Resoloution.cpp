#include "Resoloution.hpp"

#include "Border.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Hud.hpp"
#include "Menu.hpp"
#include "Options.hpp"
#include "Difficulty.hpp"
#include "GameState.hpp"
#include "WindowManager.hpp"
#include "BrickSetter.hpp"
#include "Video.hpp"
#include "VolumeManager.hpp"
#include "ControlSettingsMenu.hpp"
#include "MenuScreenHandler.hpp"

int Resoloution::m_count;

Resoloution::Resoloution(WindowManager &window
    , Border &border
    , Paddle &paddle
    , Brick &brick
    , Hud &hud
    , Menu &menu
    , Options &options
    , Difficulty &difficulty
    , Video &video
    , ControlSettingsMenu &controlSettingsMenu
    , VolumeManager &volume
    , MenuScreenHandler &menuScreenHandler
)
: m_window(window)
, m_border(border)
, m_paddle(paddle)
, m_brick(brick)
, m_hud(hud)
, m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_controlSettingsMenu(controlSettingsMenu)
, m_volume(volume)
, m_initialWindowSize(800,600)
, m_firstBrickPos(75,60)
, m_menuScreenHandler(menuScreenHandler)
{
    m_count = 0; 
}

void Resoloution::updateLayout(const sf::Vector2u &windowSize)
{
    updateTextPositions(windowSize);
    updateBrickPositions(windowSize);
    updateScoreTextPosition(windowSize);
    updateBorderPosition(windowSize);
    updatePaddlePosition(windowSize);
}

void Resoloution::changeResolution(sf::VideoMode videoMode)
{
    m_window.getRenderWindow().create(videoMode, "Arkanoid-game", sf::Style::Default);
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2i windowPosition(desktopMode.width / 2 - m_window.getSize().x / 2, desktopMode.height / 2 - m_window.getSize().y / 2);
    m_window.getRenderWindow().setPosition(windowPosition);
    m_window.getRenderWindow().setFramerateLimit(60);

    sf::Vector2u windowSize = m_window.getSize();
    sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
    m_window.getRenderWindow().setView(view);
    updateLayout(windowSize);
}

void Resoloution::setPositionsWithOffset(std::vector<std::shared_ptr<MenuOption>> , const sf::Vector2u &windowSize, int )
{
    m_menuScreenHandler.updatePos(windowSize);
}

void Resoloution::updateTextPositions(const sf::Vector2u &windowSize)
{
    setPositionsWithOffset(m_menu.getTexts(), windowSize, 100);
    setPositionsWithOffset(m_options.getTexts(), windowSize, 200);
    setPositionsWithOffset(m_difficulty.getTexts(), windowSize, 100);
    setPositionsWithOffset(m_video.getTexts(), windowSize, 100);
    m_volume.updateText(windowSize);
    m_controlSettingsMenu.updateText(windowSize);
}

void Resoloution::updateBrickPositions(const sf::Vector2u& videoMode)
{
    sf::Vector2f offsetSize;
    if (videoMode.x == 1024) {
        offsetSize = sf::Vector2f(videoMode.x/2 - (m_brick.getShape()->getGlobalBounds().width *15), 20);
        updateBrickPositionsForResolution(offsetSize);
    } else if (videoMode.x == 800) {
        offsetSize = sf::Vector2f(videoMode.x/2 - (m_brick.getShape()->getGlobalBounds().width *15), 20);
        updateBrickPositionsForResolution(offsetSize);
    } else if (videoMode.x == 1920) {
        offsetSize = sf::Vector2f(videoMode.x/2 - (m_brick.getShape()->getGlobalBounds().width *15), 20);
        updateBrickPositionsForResolution(offsetSize);
    } else {
        std::cout << "Error!!!\n";
    }
}

void Resoloution::updateBrickPositionsForResolution(const sf::Vector2f& offsetSize)
{

    auto level = m_brick.getCurrLevelBricks();
    BrickSetter::getInstance()->deleteAllBricks();
    sf::Vector2f positionOffset(offsetSize);

    int i = -1;
    int j = -1;
    for (auto& row : *level) {
        ++j;
        std::vector<BrickLevel> spriteBricks = {};
        for (auto& brickLevel : row) {
            ++i;
            sf::Sprite& brickSprite = brickLevel.sprite;
            std::string& BrickColor = brickLevel.color;
            sf::Vector2f currentPosition = m_brickVecPos[j][i].sprite.getPosition();
            sf::Vector2f newPosition = currentPosition + positionOffset;
            brickSprite.setPosition(newPosition);
            spriteBricks.push_back({ BrickColor, brickSprite });
        }
        i = -1;
        BrickSetter::getInstance()->setBricks(spriteBricks);
    }
    m_brick.initializeLevels();
}



void Resoloution::setVec(std::vector<std::vector<BrickLevel>> bricks)
{
    m_brickVecPos = bricks;
}


void Resoloution::updateScoreTextPosition(const sf::Vector2u &windowSize)
{
    m_hud.updateResoloution(windowSize);
}

void Resoloution::updateBorderPosition(const sf::Vector2u &windowSize)
{
    m_border.getShape()->setSize(sf::Vector2f(windowSize.x - 5, windowSize.y - 5));
}

void Resoloution::updatePaddlePosition(const sf::Vector2u &windowSize)
{
    m_paddle.setPosition(m_paddle.getCenterPosition().x, windowSize.y - 25);
}
