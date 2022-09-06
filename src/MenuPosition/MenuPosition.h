#ifndef MENUPOSITION_H
#define MENUPOSITION_H

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "../Pair/Pair.h"

class MenuPosition
{
public:
    MenuPosition();
    MenuPosition(Pair<uint8_t, uint8_t> position, Pair<uint8_t, uint8_t> dimensions);
    ~MenuPosition();

    void SetPreviousItem();
    void SetNextItem();
    void SetPreviousCategory();
    void SetNextCategory();

    uint8_t GetItem();
    uint8_t GetNextItem();
    uint8_t GetCategory();

private:
    Pair<uint8_t, uint8_t> position;
    Pair<uint8_t, uint8_t> dimensions;
};

#endif