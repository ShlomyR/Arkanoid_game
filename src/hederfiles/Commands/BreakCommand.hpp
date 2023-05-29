#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class BreakCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};
