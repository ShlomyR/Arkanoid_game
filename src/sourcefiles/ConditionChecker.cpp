#include "ConditionChecker.hpp"
#include "WhileCommand.hpp"
#include "SymbolVar.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

ConditionChecker::ConditionChecker()
: m_whileCommand()
{
    initMap();
}

bool ConditionChecker::isNumber(const std::string &str) 
{
    auto it = std::find_if_not(str.begin(), str.end(), ::isdigit);
    return it == str.end();
}

bool ConditionChecker::check(const std::vector<std::string>& line)
{
    if (line.size() < 4) {
        throw std::invalid_argument("Invalid condition");
    }
    const std::string& lhs = line[1];
    const std::string& op = line[2];
    const std::string& rhs = line[3];

    if (!isNumber(lhs) && isNumber(rhs)) {
        return checkStringNumberComparison(line, op, stod(rhs));
    } else if (isNumber(lhs) && !isNumber(rhs)) {
        return checkNumberStringComparison(line, stod(lhs), op);
    } else if (!isNumber(lhs) && !isNumber(rhs)) {
        return checkStringComparison(lhs, op, rhs);
    } else if (isNumber(lhs) && isNumber(rhs)) {
        return checkNumberComparison(stod(lhs), op, stod(rhs));
    } else {
        throw std::runtime_error("This type of checking is not suported!!!");
    }
}

bool ConditionChecker::checkComparison(const double lhs, const std::string &op, const double rhs)
{
    if (m_comparison_map.find(op) == m_comparison_map.end()) {
        throw std::invalid_argument("Unknown comparison operator");
    }

    return (this->*m_comparison_map[op])(lhs, rhs);
}

bool ConditionChecker::checkStringNumberComparison(const std::vector<std::string> &line, const std::string &op, const double rhs)
{
    const double lhs = (SymbolVar::getInstance()->getMapStr().count(line[1]) > 0) ? m_whileCommand.getVal(line) : m_whileCommand.getVal(line[1]);
    return checkComparison(lhs, op, rhs);
}

bool ConditionChecker::checkNumberStringComparison(const std::vector<std::string> &line, const double lhs, const std::string &op)
{
    const double rhs = m_whileCommand.getVal(line[3]);

    return checkComparison(lhs, op, rhs);
}

bool ConditionChecker::checkStringComparison(const std::string &lhs, const std::string &op, const std::string &rhs)
{
    return checkComparison(m_whileCommand.getVal(lhs), op, m_whileCommand.getVal(rhs));
}

bool ConditionChecker::checkNumberComparison(const double lhs, const std::string &op, const double rhs)
{
    return checkComparison(lhs, op, rhs);
}

bool ConditionChecker::less_than(double lhs, double rhs)
{
    return lhs < rhs;
}

bool ConditionChecker::greater_than(double lhs, double rhs)
{
    return lhs > rhs;
}

bool ConditionChecker::equal_to(double lhs, double rhs)
{
    return lhs == rhs;
}

bool ConditionChecker::less_than_or_equal_to(double lhs, double rhs)
{
    return lhs <= rhs;
}

bool ConditionChecker::greater_than_or_equal_to(double lhs, double rhs)
{
    return lhs >= rhs;
}

bool ConditionChecker::not_equal_to(double lhs, double rhs)
{
    return lhs != rhs;
}

void ConditionChecker::initMap()
{
    m_comparison_map = {
        {"<", &ConditionChecker::less_than},
        {">", &ConditionChecker::greater_than},
        {"==", &ConditionChecker::equal_to},
        {"<=", &ConditionChecker::less_than_or_equal_to},
        {">=", &ConditionChecker::greater_than_or_equal_to},
        {"!=", &ConditionChecker::not_equal_to}
    };
}
