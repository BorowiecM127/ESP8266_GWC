#ifndef LCD_H
#define LCD_H

#pragma once

#include <LiquidCrystal.h>
#include "../../Constants/Constants.h"

class LCD
{
public:
    LCD();
    ~LCD();

    void Init();
    void Display(String lines[2]);

private:
    LiquidCrystal liquidCrystal;
};

#endif