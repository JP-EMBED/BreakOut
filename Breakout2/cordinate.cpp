#include "cordinate.h"

Cordinate::Cordinate(int x, int y)
    :m_x(x), m_y(y)
{}

Cordinate::Cordinate(const Cordinate& copy)
    :m_x(copy.m_x), m_y(copy.m_y)
{}

Cordinate::~Cordinate()
{}

Cordinate& Cordinate::operator=(const Cordinate& rhs)
{
    if(this != &rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
    }

    return *this;
}
