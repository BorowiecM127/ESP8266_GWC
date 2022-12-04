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
    LCD(const LCD &screen);
    LCD &operator=(const LCD &screen);

    void begin();
    void display(String lines[2], bool lineIsEdited);

private:
    LiquidCrystal liquidCrystal;
};

#endif