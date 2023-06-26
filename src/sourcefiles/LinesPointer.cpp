#include "LinesPointer.hpp"

#include <iostream>

size_t LinesPointer::m_pointerCounter;

LinesPointer::LinesPointer()
{
    m_pointerCounter = 0;
}

void LinesPointer::incrementIndex()
{
    m_pointerCounter++;
}

void LinesPointer::setIndex(size_t i)
{
    m_pointerCounter = i;
}

void LinesPointer::addToIndex(size_t i)
{
    m_pointerCounter += i;
}

size_t LinesPointer::getIndex()
{
    return m_pointerCounter;
}

void LinesPointer::resetIndex()
{
    m_pointerCounter = 0;
}
