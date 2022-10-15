#include "LCD.h"

LCD::LCD(): liquidCrystal(NULL, NULL, NULL, NULL, NULL, NULL)
{

}

LCD::~LCD()
{

}

void LCD::Init()
{
    liquidCrystal = LiquidCrystal(LCDPins[0], LCDPins[1], LCDPins[2], LCDPins[3], LCDPins[4], LCDPins[5]);
    liquidCrystal.begin(16, 2);
    liquidCrystal.clear();
}

void LCD::Display(String lines[2])
{
    liquidCrystal.clear();
    liquidCrystal.print(">");
    liquidCrystal.print(lines[0]);
    liquidCrystal.setCursor(1, 1);
    liquidCrystal.print(lines[1]);
}