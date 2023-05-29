#pragma once

#include <exception>
#include <string>

class MapException : public std::exception {
public:
    MapException(const std::string &, const std::string &);

    const char* what() const noexcept override;
    const char* where() const noexcept;
private:
    std::string m_message;
    std::string m_location;
};