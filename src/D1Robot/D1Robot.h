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

    void Init();
    void UpdateScreen(String lines[2]);
    analogKey ReadAnalogButton();

private:
    LCD screen;
    AnalogButton button;
};

#endif