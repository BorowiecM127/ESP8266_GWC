#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

#pragma once

#include <stdint.h>
#include <Arduino.h>
#include <pins_arduino.h>
#include <LiquidCrystal.h>
#include "../MenuPosition/MenuPosition.h"
#include "../ActionHandler/ActionHandler.h"
#include "../Pair/Pair.h"

class ScreenHandler
{
public:
    ScreenHandler();
    ~ScreenHandler();

    void Init(const uint8_t pins[6], uint8_t aPin, Pair<uint8_t, uint8_t> menuDimensions);
    void Update(String menuLines[3][2]);

private:
    void PrintMenu(String menuLines[3][2]);
    void SetMenuPosition();

    LiquidCrystal lcd;
    MenuPosition menuPosition;
    ActionHandler actionHandler;
};

#endif