#ifndef CONSTANTS_H
#define CONSTANTS_H

// Uncomment line below to test actuator
// #define DEBUG

#pragma once

#include "../Pair/Pair.h"
#include <stdint.h>
#include <Arduino.h>

// KEYPAD SHIELD CONSTANTS
const uint8_t LCDPins[6] = {D7, D8, D3, 1, D5, D6};
const uint8_t analogPin = A0;

enum analogKey {
    noneKey = 0,
    selectKey = 1,
    leftKey = 2,
    downKey = 3,
    upKey = 4,
    rightKey = 5
};

// DS18B20 CONSTANTS
const uint8_t oneWirePin = 3;
const int refreshDivider = 4;

//  MENU CONSTANTS
const uint8_t categoriesCount = 3;
const uint8_t linesCount = 2;
const float coarseModifierValue = 1.0;
const float fineModifierValue = 0.5;

const float defaultTemperatures[categoriesCount][linesCount] = {
    {15.0, 20.0},
    {5.0, 25.0},
    {5.0, 5.0}
};

const String defaultTitles[categoriesCount][linesCount] = {
    {"T_in: ",
     "T_out: "},
    {"Tw_in: ",
     "Tw_out: "},
    {"dT_in: ",
     "dT_out: "}
};

const bool defaultEditables[categoriesCount][linesCount] = {
    {false, false},
    {true, true},
    {true, true}
};

//MAIN CONSTANTS
const uint16_t serialBaudRate = 9600;
const uint16_t loopDelayMs = 200;

//ACTUATOR CONSTANTS
#ifndef DEBUG
    enum actuatorCheckTimeMin {
        off = 60,
        on = 15,
        initial = 2
    };
#else
    enum actuatorCheckTimeMin {
        off = 0,
        initial = 1,
        on = 2
    };
#endif

const uint8_t degrees5Pin = D0;
const uint8_t degrees85Pin = D1;
const uint8_t triggerPin = D4;
const uint8_t rotationPin = D2;

const uint8_t ESP8266High = LOW;
const uint8_t ESP8266Low = HIGH;

const uint8_t clockwise = LOW;

#endif