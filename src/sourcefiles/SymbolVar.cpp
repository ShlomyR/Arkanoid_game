#include "MapException.hpp"
#include "SymbolVar.hpp"

#include <iostream>
#include <string>
#include <vector>

SymbolVar* SymbolVar::getInstance()
{
    static SymbolVar m_instance;
    return &m_instance;
}

std::unordered_map<std::string,double> SymbolVar::creatDataBaseMap(std::string key,double const& val)
{    
    this->map_doubleDB[key] = val;

    return this->map_doubleDB;    
}

std::unordered_map<std::string, std::string> SymbolVar::creatDataBaseMap(std::string key, std::string const &val)
{
    this->map_strDB[key] = val;

    return this->map_strDB; 
}

void SymbolVar::createVar(std::vector<std::string> const &var_arr)
{
    if (var_arr[3] == "bind") {
        this->checkDup(var_arr[1]);
        this->assignVar(var_arr);
    } else {
        this->getVarValue(var_arr);
    }   
}

void SymbolVar::assignVar(std::vector<std::string> const &var_arr)
{
    if (!m_conditionCheck.isNumber(var_arr[4])) {
        this->creatDataBaseMap(var_arr[1],var_arr[4]);
        this->vec_all_vars.push_back(this->map_strDB.find(var_arr[1])->first);
    } else {
        this->creatDataBaseMap(var_arr[1],stod(var_arr[4]));
        this->vec_all_vars.push_back(this->map_doubleDB.find(var_arr[1])->first);
    }
}

void SymbolVar::checkDup(std::string var_arr)
{
    for (size_t i = 0; i < this->vec_all_vars.size(); i++) {
        if (var_arr == this->vec_all_vars[i]) {
            this->vec_all_vars.erase(this->vec_all_vars.begin() + i);
        } else {
            continue;
        }
    }

}

void SymbolVar::getVarValue(std::vector<std::string> const &var_arr)
{
    if (var_arr.size() == 3) {
        if (!m_conditionCheck.isNumber(var_arr[2])) {
            setVariable(var_arr[0], var_arr[2], "map_strDB");
        } else {
            setVariable(var_arr[0], var_arr[2], "map_doubleDB");
        }
    } else {
        if (!m_conditionCheck.isNumber(var_arr[3])) {
            setVariable(var_arr[1], var_arr[3], "map_strDB");
        } else {
            setVariable(var_arr[1], var_arr[3], "map_doubleDB");
        }
    }
}

template <typename K, typename V>
void SymbolVar::printMap(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

template<typename K>
void SymbolVar::printMap(std::vector<K> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair <<"}\n";
    }
}

std::unordered_map<std::string, std::string> &SymbolVar::getMapStr()
{
    return map_strDB;
}

std::unordered_map<std::string, double> &SymbolVar::getMapDouble()
{
    return map_doubleDB;
}

std::vector<std::string> &SymbolVar::getVecAllVars()
{
    return vec_all_vars;
}

void SymbolVar::setVariable(const std::string& varName, const std::string& varValue, const std::string& mapName)
{
    try {
        if (map_strDB.count(varValue)) {
            this->creatDataBaseMap(varName, this->map_strDB.at(varValue));
            this->vec_all_vars.push_back(this->map_strDB.find(varName)->first);
        } else if (map_doubleDB.count(varValue)) {
            this->creatDataBaseMap(varName, this->map_doubleDB.at(varValue));
            this->vec_all_vars.push_back(this->map_doubleDB.find(varName)->first);
        } else {
            throw MapException("Error: " + varValue + " not found in " + mapName + ".", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
    }
}
