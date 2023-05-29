#pragma once

#include "ConditionChecker.hpp"

#include <unordered_map>
#include <string>
#include <vector>

class SymbolVar
{
public:
    static SymbolVar* getInstance();
public:
    void createVar(std::vector<std::string> const&);
    std::unordered_map<std::string,double> creatDataBaseMap(std::string,double const&);
    std::unordered_map<std::string,std::string> creatDataBaseMap(std::string,std::string const&);
    std::unordered_map<std::string,std::string>& getMapStr();
    std::unordered_map<std::string,double>& getMapDouble();
    std::vector<std::string>& getVecAllVars();
private:
    SymbolVar() = default;
    SymbolVar(const SymbolVar&) = delete;
    SymbolVar& operator=(const SymbolVar&) = delete;

    void assignVar(std::vector<std::string> const &);
    void checkDup(std::string);
    void getVarValue(std::vector<std::string> const&);
    void setVariable(const std::string&, const std::string&, const std::string&);

    template<typename K, typename V>
    void printMap(std::unordered_map<K, V> const&);
    template<typename K>
    void printMap(std::vector<K> const &);
private:
    std::unordered_map<std::string,std::string> map_strDB;
    std::unordered_map<std::string,double> map_doubleDB;
    std::vector<std::string>  vec_all_vars;
    ConditionChecker m_conditionCheck;
};
