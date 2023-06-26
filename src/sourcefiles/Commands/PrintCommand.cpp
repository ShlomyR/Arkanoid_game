#include "PrintCommand.hpp"
#include "MapException.hpp"
#include "SymbolVar.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void PrintCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() > 2) {
        printCurly(line);
    } else {
        printFunc(line[1]);
    }
}

void PrintCommand::printFunc(std::string const val)
{
    std::string val_name = val;
    double val_d = 0.0;
    

    for (std::string::size_type i = 0; i < SymbolVar::getInstance()->getVecAllVars().size(); i++) {
        if (val == SymbolVar::getInstance()->getVecAllVars()[i]) {
            try {
                if (SymbolVar::getInstance()->getMapDouble().count(SymbolVar::getInstance()->getMapStr().at(val))) {
                    val_d = SymbolVar::getInstance()->getMapDouble().at(SymbolVar::getInstance()->getMapStr().at(val));
                } else {
                    throw MapException("Error: " + val + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
                }
            } catch (const MapException& me) {
                std::cout << me.what() << " at line " << me.where() << "\n";
            }

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
        for (std::string::size_type j = 0; j < SymbolVar::getInstance()->getVecAllVars().size(); j++) {
            temp_val = line[i];
            if (temp_val == SymbolVar::getInstance()->getVecAllVars()[j]) {
                temp_val.erase(std::remove_if(temp_val.begin(), temp_val.end(), ::isspace), temp_val.end());
                try {
                    if (SymbolVar::getInstance()->getMapDouble().count(temp_val)) {
                        val_i = SymbolVar::getInstance()->getMapDouble().at(temp_val);
                    } else {
                        throw MapException("Error: " + temp_val + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
                    }
                } catch (const MapException& me) {
                    std::cout << me.what() << " at line " << me.where() << "\n";
                }
                
                if (line[i+1] == "++") {
                    val_i++;
                } if (line[i+1] == "--") {
                    val_i--;
                }
                SymbolVar::getInstance()->getMapDouble().at(temp_val) = val_i;
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
