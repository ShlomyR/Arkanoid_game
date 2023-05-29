#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class PrintCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void printFunc(std::string);
    void printCurly(std::vector<std::string> const&);
};
