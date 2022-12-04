#include "Object.hpp"

// object constructor implementation
Object::Object(int day)
{
    set_day(day);
}

// object member function implementation
void Object::set_day(int day)
{
  m_day = day;
}