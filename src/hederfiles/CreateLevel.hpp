#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

class CreateLevel
{
public:
    CreateLevel() = default;
    ~CreateLevel() = default;
    
    void create(std::string pos, std::string const containerType, std::string const str);
};