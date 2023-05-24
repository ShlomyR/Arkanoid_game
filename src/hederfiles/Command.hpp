#pragma once

#include <string>
#include <vector>

#include "Command.hxx"


// class GameCommand : public Command
// {
// public:
//     int DoCommand(std::vector<std::string> const&) override;
// };

// class MenuCommand : public Command
// {
// public:
//     ~MenuCommand()
//     {
//         delete menu;
//     }
//     int DoCommand(std::vector<std::string> const&) override;
// private:
//     Menu* menu;
// };

// class BrickCommand : public Command
// {
// public:
//     ~BrickCommand()
//     {
//         delete brick;
//     }
//     int DoCommand(std::vector<std::string> const&) override;
// private:
//     Bricks* brick;
// };

// class BallCommand : public Command
// {
// public:
//     ~BallCommand()
//     {
//         delete ball;
//     }
//     int DoCommand(std::vector<std::string> const&) override;
// private:
//     Ball* ball;
// };

// class PaddleCommand : public Command
// {
// public:
//     ~PaddleCommand()
//     {
//         delete paddle;
//     }
//     int DoCommand(std::vector<std::string> const&) override;
// private:
//     Paddle* paddle;
// };

// class InformationCommand : public Command
// {
// public:
//     ~InformationCommand()
//     {
//         delete information;
//     }
//     int DoCommand(std::vector<std::string> const&) override;
// private:
//     Information* information;
// };
class PosCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    
};

class VerCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
};

class EqualMapCommand : public Command
{
public:    
    int DoCommand(std::vector<std::string> const&) override;
private:
    void updateFromDB(std::vector<std::string> const&);
    void convertFromChToNum(std::vector<std::string> const&);
};

class WhileCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
    static double getVal(std::vector<std::string> const&);
    static double getVal(std::string const&);
    static std::string getStringVal(std::vector<std::string> const&);
    static std::string getStringVal(std::string const&);
};

class IfCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void ifFunc(std::string);
};

class SleepCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void sleepFunc(std::string);
};

class PrintCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void printFunc(std::string const);
    void printCurly(std::vector<std::string> const&);
};

class BreakCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};