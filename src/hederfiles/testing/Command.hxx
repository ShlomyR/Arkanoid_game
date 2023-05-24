#pragma once

#include <string>
#include <vector>

class Command
{
public:
    virtual int DoCommand(std::vector<std::string> const&) = 0;
    virtual ~Command() = default;
};

#include "Command.hxx"