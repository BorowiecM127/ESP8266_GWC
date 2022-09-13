#include "MenuPositions.h"

MenuPositions::MenuPositions()
    : position(),
      dimensions()
{
}

MenuPositions::MenuPositions(
    Pair<uint8_t, uint8_t> position, 
    Pair<uint8_t, uint8_t> dimensions, 
    bool **editablePositions)
    : position(position),
      dimensions(dimensions)
{
    positions = new Position*[dimensions.first]();

    for(int i = 0; i < dimensions.first; ++i)
    {
        positions[i] = new Position[dimensions.second]();
    }

    for(int i = 0; i < dimensions.first; ++i)
    {
        for(int j = 0; j < dimensions.second; ++j)
        {
            positions[i][j].isEditable = editablePositions[i][j];
            positions[i][j].isEdited = false;
        }
    }
}

MenuPositions::~MenuPositions()
{
    for(int i = 0; i < dimensions.first; ++i)
    {
        delete(positions[i]);
    }

    delete(positions);
}

void MenuPositions::SetPreviousItem()
{
    position.second = abs((position.second - 1) % dimensions.second);
}

void MenuPositions::SetNextItem()
{
    position.second = (position.second + 1) % dimensions.second;
}

void MenuPositions::SetPreviousCategory()
{
    position.first = abs((position.first - 1) % dimensions.first);
}

void MenuPositions::SetNextCategory()
{
    position.first = (position.first + 1) % dimensions.first;
}

void MenuPositions::ToggleEditMode()
{
    positions[position.first][position.second].isEdited = !positions[position.first][position.second].isEdited;
}

uint8_t MenuPositions::GetItem()
{
    return position.second;
}

uint8_t MenuPositions::GetNextItem()
{
    return (position.second + 1) % dimensions.second;
}

uint8_t MenuPositions::GetCategory()
{
    return position.first;
}

bool MenuPositions::GetEditMode()
{
    return positions[position.first][position.second].isEdited;
}