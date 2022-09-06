#include "MenuPosition.h"

MenuPosition::MenuPosition()
    : position(),
      dimensions()
{
}

MenuPosition::MenuPosition(Pair<uint8_t, uint8_t> position, Pair<uint8_t, uint8_t> dimensions)
    : position(position),
      dimensions(dimensions)
{
}

MenuPosition::~MenuPosition()
{
}

void MenuPosition::SetPreviousItem()
{
    position.second = abs((position.second - 1) % dimensions.second);
}

void MenuPosition::SetNextItem()
{
    position.second = (position.second + 1) % dimensions.second;
}

void MenuPosition::SetPreviousCategory()
{
    position.first = abs((position.first - 1) % dimensions.first);
}

void MenuPosition::SetNextCategory()
{
    position.first = (position.first + 1) % dimensions.first;
}

uint8_t MenuPosition::GetItem()
{
    return position.second;
}

uint8_t MenuPosition::GetNextItem()
{
    return (position.second + 1) % dimensions.second;
}

uint8_t MenuPosition::GetCategory()
{
    return position.first;
}