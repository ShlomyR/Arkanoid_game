#pragma once

#include "WhileCommand.hpp"

#include <unordered_map>
#include <string>
#include <vector>

class ConditionChecker 
{
public:
    ConditionChecker();
    
    bool check(const std::vector<std::string> &);
    bool isNumber(const std::string &);
private:
    ConditionChecker(const ConditionChecker &) = delete;
    ConditionChecker& operator=(const ConditionChecker&) = delete;

    bool checkStringNumberComparison(const std::vector<std::string> &, const std::string &, const double);
    bool checkNumberStringComparison(const std::vector<std::string> &, const double, const std::string &);
    bool checkStringComparison(const std::string &, const std::string &, const std::string &);
    bool checkNumberComparison(const double, const std::string &, const double);
    bool checkComparison(const double, const std::string &, const double);

    bool less_than(const double, const double);
    bool greater_than(const double, const double);
    bool equal_to(const double, const double);
    bool less_than_or_equal_to(const double, const double);
    bool greater_than_or_equal_to(const double, const double);
    bool not_equal_to(const double, const double);

    void initMap();
private:
    WhileCommand m_whileCommand;
    std::unordered_map<std::string, bool (ConditionChecker::*)(const double, const double)> m_comparison_map;
};
