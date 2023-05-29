#include "InitObjectsCommand.hpp"
#include "InitObjects.hpp"
#include "WhileCommand.hpp"

void InitObjectsCommand::DoCommand(std::vector<std::string> const&line)
{
    WhileCommand wc;
    sf::Vector2u windowSize = sf::Vector2u (std::min(800u, sf::VideoMode::getDesktopMode().width), std::min(600u, sf::VideoMode::getDesktopMode().height));
    std::string gameTitle = line[1];
    int health = wc.getVal(line[2]);
    int level = wc.getVal(line[3]);
    int finaleLevel = wc.getVal(line[4]);
    InitObjects io(windowSize, gameTitle, health,level, finaleLevel);
    io.init();
    io.run();
}