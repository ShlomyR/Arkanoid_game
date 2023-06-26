#pragma once

#include <vector>
#include <string>

class ifCondition
{
public:
    static void ifCon(std::vector<std::string> const&);
private:
    ifCondition(const ifCondition&) = delete;
    ifCondition& operator=(const ifCondition&) = delete;
};
