#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class IfCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void ifFunc(std::string);
};
