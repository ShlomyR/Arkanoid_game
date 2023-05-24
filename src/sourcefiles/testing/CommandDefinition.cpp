#include <unistd.h>
#include <iostream>
#include <algorithm>

// #include "Command.hpp"
// #include "Parser.hpp"
// #include "SymbolVar.hpp"
// #include "CheckCondition.hpp"
// #include "Command.hpp"

#include "../hederfiles/testing/Command.hpp"
#include "../hederfiles/testing/Parser.hpp"
#include "../hederfiles/testing/SymbolVar.hpp"
#include "../hederfiles/testing/CheckCondition.hpp"
#include "../hederfiles/testing/Command.hpp"


void EqualMapCommand::updateFromDB(std::vector<std::string> const&line)
{
    if (!isNumber(line[2])) {
        SymbolVar::getInstance()->map_strDB.at(line[0]) = line[2];
    } else {
        SymbolVar::getInstance()->map_doubleDB.at(line[0]) = stod(line[2]);
    }
}

void EqualMapCommand::convertFromChToNum(std::vector<std::string> const&)
{
    // ShuntingYardToken::setCopy(line);
    // double d = 0.0;
    // int dtoi = 0;
    // std::string str;

    // for (std::string::size_type i = 0; i < line.size(); i++) {
    //     for (std::string::size_type j = 0; j < SymbolVar::getInstance()->vec_all_vars.size(); j++) {
    //         if (line[i] == SymbolVar::getInstance()->vec_all_vars[j] && line[0] != SymbolVar::getInstance()->vec_all_vars[j]) {
    //             if (line[i] == "h0") {
    //                 d = SymbolVar::getInstance()->map_double.at(ShuntingYardToken::getCopy()[i]);
    //             }
    //             else {
    //                 d = SymbolVar::getInstance()->map_double.at(SymbolVar::getInstance()->map_doubleDB.at(ShuntingYardToken::getCopy()[i]));
    //             }
    //             dtoi = d;
    //             str = std::to_string(dtoi);
    //             ShuntingYardToken::setCopy(str,i);
    //         }
    //     }
    // }
}

double WhileCommand::getVal(std::vector<std::string> const&line)
{

    double val = SymbolVar::getInstance()->map_doubleDB.at(line[1]);

    return val;
}

double WhileCommand::getVal(std::string const&line)
{
    double val = SymbolVar::getInstance()->map_doubleDB.at(line);

    return val;
}

std::string WhileCommand::getStringVal(std::vector<std::string> const&line)
{
    std::string val = SymbolVar::getInstance()->map_strDB.at(line[1]);

    return val;
}

std::string WhileCommand::getStringVal(std::string const&line)
{
    std::string val = SymbolVar::getInstance()->map_strDB.at(line);

    return val;
}

void SleepCommand::sleepFunc(std::string val)
{
    std::cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
}

void PrintCommand::printFunc(std::string const val)
{
    std::string val_name = val;

    for (std::string::size_type i = 0; i < SymbolVar::getInstance()->vec_all_vars.size(); i++) {
        if (val == SymbolVar::getInstance()->vec_all_vars[i]) {
            double val_d = SymbolVar::getInstance()->map_doubleDB.at(val);
            std::cout << val_name << ": " << val_d << "\n";
        }
    }
    if (val[0] == '"') {    
        std::cout << "\n" << val << "\n";   
    }
}

void PrintCommand::printCurly(std::vector<std::string> const&line)
{
    std::string val = " ";
    std::string temp_val = " ";
    std::string temp_res = "";
    int val_i = 0;
    for (std::string::size_type i = 1; i < line.size(); i++) {
        for (std::string::size_type j = 0; j < SymbolVar::getInstance()->vec_all_vars.size(); j++) {
            temp_val = line[i];
            if (temp_val == SymbolVar::getInstance()->vec_all_vars[j]) {
                temp_val.erase(std::remove_if(temp_val.begin(), temp_val.end(), ::isspace), temp_val.end());
                val_i = SymbolVar::getInstance()->map_doubleDB.at(temp_val);
                if (line[i+1] == "++") {
                    val_i++;
                } if (line[i+1] == "--") {
                    val_i--;
                }
                SymbolVar::getInstance()->map_doubleDB.at(temp_val) = val_i;
                temp_res = std::to_string(val_i);
                if (line[i+1][0] != '}')
                {
                    i++;
                    i++;
                }
                val += temp_res + " ";
            }
        }
        val+=  line[i] + " ";
    }
    std::cout << "\n" << val << "\n";
}

