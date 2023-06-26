#include "MapException.hpp"

#include <string>

MapException::MapException(const std::string& message, const std::string& location)
: m_message(message)
, m_location(location)
{}

const char *MapException::what() const noexcept
{
    return m_message.c_str();
}

const char* MapException::where() const noexcept
{
    return m_location.c_str();
}
