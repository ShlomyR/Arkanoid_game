#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class LevelCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
};