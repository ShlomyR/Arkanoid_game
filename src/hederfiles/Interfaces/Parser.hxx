#pragma once

#include <string>
#include <vector>

class Parser
{
public:
    virtual ~Parser() = default;
    virtual void parse(std::vector<std::vector<std::string>> &) = 0;
};