#ifndef D1ROBOT_H
#define D1ROBOT_H

#pragma once

#include "LCD/LCD.h"
#include "AnalogButton/AnalogButton.h"

class D1Robot
{
public:
    D1Robot();
    ~D1Robot();

    void begin();
    void updateScreen(String lines[2], bool lineIsEdited);
    analogKey readAnalogButton();

private:
    LCD screen;
    AnalogButton button;
};

#endif