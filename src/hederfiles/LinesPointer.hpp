#pragma once

#include <iostream>

class LinesPointer
{
public:
    LinesPointer();
    static void incrementIndex();
    static void setIndex(size_t);
    static size_t getIndex();
    static void addToIndex(size_t);
    void resetIndex();
private:
    static size_t m_pointerCounter;
};