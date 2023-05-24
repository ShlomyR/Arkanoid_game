#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// #include "CheckCondition.hpp"
// #include "Command.hpp"

#include "../hederfiles/testing/CheckCondition.hpp"
#include "../hederfiles/testing/Command.hpp"

bool isNumber(const std::string &str)
{
    auto it = std::find_if_not(str.begin(), str.end(), ::isdigit);
    return it == str.end();
}

bool CheckCondition(std::vector<std::string> const&line)
{
    double val_from_DB = 0.0;
    std::string str_from_DB = "";
    if (line[2] == "<") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line)) < line[3];
        } else {
            return (val_from_DB = WhileCommand::getVal(line)) < stoi(line[3]);
        }
    } else if (line[2] == ">") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line)) > line[3];
        } else {
            return (val_from_DB = WhileCommand::getVal(line)) > stoi(line[3]);
        }
    } else if (line[2] == "==") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line[1]))
                     == 
                    (str_from_DB = WhileCommand::getStringVal(line[3]));
        } else {
            return ((val_from_DB = WhileCommand::getVal(line)) == stoi(line[3]));
        }
    } else if (line[2] == "<=") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line)) <= line[3];
        } else {
            return (val_from_DB = WhileCommand::getVal(line)) <= stoi(line[3]);
        }
    } else if (line[2] == ">=") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line)) >= line[3];
        } else {
            return (val_from_DB = WhileCommand::getVal(line)) >= stoi(line[3]);
        }
    } else if (line[2] == "!=") {
        if (!isNumber(line[3])) {
            return (str_from_DB = WhileCommand::getStringVal(line)) != line[3];
        } else {
            return (val_from_DB = WhileCommand::getVal(line)) != stoi(line[3]);
        }
    } else {
        throw std::runtime_error("This is unknown condition");
    }
}