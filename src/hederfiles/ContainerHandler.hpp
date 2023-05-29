#include <iostream>
#include <vector>
#include <tuple>

template <typename... Args>
void printTuple(const std::tuple<Args...>& tuple) {
    std::apply([](const auto&... args) {
        ((std::cout << args << ' '), ...);
        std::cout << "\n";
    }, tuple);
}

template <typename T>
void printVector(const std::vector<T>& vector) {
    for (const auto& item : vector) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

template <typename... Args>
void printVectorOfTuples(const std::vector<std::tuple<Args...>>& vectorOfTuples) {
    for (const auto& tuple : vectorOfTuples) {
        printTuple(tuple);
    }
}

class ContainerHandler
{
public:
    std::vector<std::tuple<int, std::string, std::string>> createLevel(const std::string& str, const std::string&, std::vector<int>&, std::vector<std::string>&, std::vector<std::string>&);
private:
    size_t convertStringToVectors(const std::string& str, std::vector<int>&, std::vector<std::string>&, std::vector<std::string>&);
};
