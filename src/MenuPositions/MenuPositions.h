#ifndef MENUPOSITION_H
#define MENUPOSITION_H

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "../Pair/Pair.h"

class MenuPositions
{
public:
    MenuPositions();
    MenuPositions(
        Pair<uint8_t, uint8_t> position, 
        Pair<uint8_t, uint8_t> dimensions, 
        bool **editablePositions);
    ~MenuPositions();

    void SetPreviousItem();
    void SetNextItem();
    void SetPreviousCategory();
    void SetNextCategory();
    void ToggleEditMode();

    uint8_t GetItem();
    uint8_t GetNextItem();
    uint8_t GetCategory();
    bool GetEditMode();

private:
    class Position
    {
    public:
        bool isEditable;
        bool isEdited;
    };

    Pair<uint8_t, uint8_t> position;
    Pair<uint8_t, uint8_t> dimensions;
    Position **positions;
};

#endif