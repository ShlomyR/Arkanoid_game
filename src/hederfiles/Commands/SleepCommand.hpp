#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class SleepCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void sleepFunc(std::string);
};
