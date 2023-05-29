#pragma once

#include <string>
#include <vector>

class Command
{
public:
    virtual ~Command() = default;
    virtual void DoCommand(std::vector<std::string> const&) = 0;
};
