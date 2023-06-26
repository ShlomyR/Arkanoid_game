#pragma once

#include <string>
#include <vector>

#include "BlockParser.hpp"

class IfBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &) override;
};