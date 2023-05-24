#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class SymbolVar
{
public:
    static SymbolVar* getInstance();
public:
    std::unordered_map<std::string,std::string> map_strDB;
    std::unordered_map<std::string,double> map_doubleDB;
    std::vector<std::string>  vec_all_vars;
    void createVar(std::vector<std::string> const&);
private:
    SymbolVar() {}
    std::unordered_map<std::string,double> creatDataBaseMap(std::string key,double const&);
    std::unordered_map<std::string,std::string> creatDataBaseMap(std::string key,std::string const&);
    void assignVar(std::vector<std::string> const &);
    void checkDup(std::string);
    void getVarValue(std::vector<std::string> const&);
    
    template<typename K, typename V>
    void printMap(std::unordered_map<K, V> const& m);
    template<typename K>
    void printMap(std::vector<K> const &m);
};