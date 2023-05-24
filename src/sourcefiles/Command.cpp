#include <iostream>


// #include "Parser.hpp"
// #include "SymbolVar.hpp"
// #include "Game.hpp"
// #include "WhileLoop.hpp"
// #include "ifCondition.hpp"
// #include "Store.hpp"

#include "../hederfiles/Parser.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/Command.hpp"


// int GameCommand::DoCommand(std::vector<std::string> const&line)
// {  
//     // if (line[1] == "init()") {
//     //     Game::getInstance()->start();
//     // } else if (line[1] == "pause()") {
//     //     Game::getInstance()->pause();
//     // } else if (line[1] == "reset()") {
//     //     Game::getInstance()->reset();
//     // } else {
//     //     throw std::runtime_error("Command not found");
//     // }


//     return 0;
// }


// int MenuCommand::DoCommand(std::vector<std::string> const&line)
// {
//     printf("Menu Command\n");

//     if (line.size() <= 2 ) {
//         std::string file_path = line[1];

//     //     this->menu = new Menu(WhileCommand::getStringVal(file_path)
//     //                         );
//     // } else {
//     //     std::string file_path = line[1];
//     //     std::string startButton = line[2]; 
//     //     std::string optionsButton = line[3];
//     //     std::string highScoreButton = line[4];
//     //     std::string exitButton = line[5];
//     //     std::string color = line[6];
//     //     std::string pos = line[7];

//     //     this->menu = new Menu(WhileCommand::getStringVal(file_path),
//     //                             WhileCommand::getStringVal(startButton),
//     //                             WhileCommand::getStringVal(optionsButton),
//     //                             WhileCommand::getStringVal(highScoreButton),
//     //                             WhileCommand::getStringVal(exitButton),
//     //                             WhileCommand::getStringVal(color),
//     //                             WhileCommand::getStringVal(pos)
//     //                             );
//     }
    

//     // Game::getInstance()->setObj(this->menu);

//     return 0;
// }

// int BrickCommand::DoCommand(std::vector<std::string> const&line)
// {
//     printf("Brick Command\n");
    

//     std::string color = line[1];
//     std::string num_of_bricks = line[2]; 
//     std::string num_of_hits = line[3];
//     std::string sound = line[4];
//     std::string file_path = line[5];

//     // this->brick = new Bricks(WhileCommand::getStringVal(color),
//     //                         WhileCommand::getStringVal(num_of_bricks),
//     //                         WhileCommand::getVal(num_of_hits),
//     //                         WhileCommand::getStringVal(sound),
//     //                         WhileCommand::getStringVal(file_path)
//     //                         );
                            
//     // Game::getInstance()->incrementMaxLevel();
//     // Game::getInstance()->setObj(this->brick);

//     return 0;
// }

// int BallCommand::DoCommand(std::vector<std::string> const&line)
// {
//     printf("Ball Command\n");
    
//     // this->ball = new Ball(WhileCommand::getStringVal(line[1]));
//     // Game::getInstance()->setObj(this->ball);

//     return 0;
// }

// int PaddleCommand::DoCommand(std::vector<std::string> const&line)
// {
//     printf("Paddle Command\n");
    
//     // this->paddle = new Paddle(WhileCommand::getStringVal(line[1]));
//     // Game::getInstance()->setObj(this->paddle);
    
//     return 0;
// }

// int InformationCommand::DoCommand(std::vector<std::string> const&line)
// {
//     printf("Information Command\n");
    
//     // this->information = new Information(WhileCommand::getVal(line[1]),
//     //                                     WhileCommand::getVal(line[2]),
//     //                                     WhileCommand::getVal(line[3]),
//     //                                     WhileCommand::getStringVal(line[4])
//     //                                     );
//     // Game::getInstance()->setObj(this->information);
    
//     return 0;
// }
int PosCommand::DoCommand(std::vector<std::string> const &)
{       
    // int posX = WhileCommand::getVal(line[1]);
    // int posY = WhileCommand::getVal(line[2]);
    
    return 1;

}


int VerCommand::DoCommand(std::vector<std::string> const&line)
{
    SymbolVar::getInstance()->createVar(line);
    
    return 0;
}

int EqualMapCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
       updateFromDB(line);
    } else if (line[1] == "++") {
        int tempIncrement = SymbolVar::getInstance()->map_doubleDB.at(line[0]);
        SymbolVar::getInstance()->map_doubleDB.at(line[0]) = ++tempIncrement;
    } else {
        SymbolVar::getInstance()->createVar(line);
    }

    return 0;
}


int WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    WhileLoop::whileLoop(line);
    return temp_row_num;
}

int IfCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    ifCondition::ifCon(line);
    return temp_row_num;
}

int SleepCommand::DoCommand(std::vector<std::string> const&line)
{
    sleepFunc(line[1]);
    return 0;
}


int PrintCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() > 2) {
        printCurly(line);
    } else {
        printFunc(line[1]);
    }
    return 0;
}