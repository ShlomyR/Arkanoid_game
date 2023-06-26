#pragma once

#include "BlockParser.hpp"

#include <string>
#include <vector>

class WhileBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &) override;
};
