#ifndef CONSTANTS_H
#define CONSTANTS_H

#pragma once

#include "../Pair/Pair.h"
#include <stdint.h>
#include <Arduino.h>

// KEYPAD SHIELD CONSTANTS
const uint8_t LCDPins[6] = {D1, D2, D4, D5, D6, D7};
const uint8_t analogPin = A0;

enum analogKey {
    noneKey = 0,
    selectKey = 1,
    leftKey = 2,
    downKey = 3,
    upKey = 4,
    rightKey = 5
};

//  MENU CONSTANTS
const uint8_t categoriesCount = 3;
const uint8_t linesCount = 2;

const float defaultTemperatures[categoriesCount][linesCount] = {
    {15.0, 20.0},
    {10.0, 30.0},
    {5.0, 5.0}
};

const String defaultTitles[categoriesCount][linesCount] = {
    {"T. 1: ",
     "T. 2: "},
    {"Tw. 1: ",
     "Tw. 2: "},
    {"Dt. 1: ",
     "Dt. 2: "}
};

const bool defaultEditables[categoriesCount][linesCount] = {
    {false, false},
    {true, true},
    {true, true}
};

#endif