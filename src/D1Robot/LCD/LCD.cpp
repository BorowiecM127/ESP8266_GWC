#include "LCD.h"

LCD::LCD()
: liquidCrystal(NULL, NULL, NULL, NULL, NULL, NULL)
{}

LCD::~LCD()
{}

LCD::LCD(const LCD &screen)
: liquidCrystal(screen.liquidCrystal)
{}

LCD &LCD::operator=(const LCD &screen)
{
    if (&screen != this)
        this->liquidCrystal = screen.liquidCrystal;
    
    return *this;
}

void LCD::begin()
{
    liquidCrystal = LiquidCrystal(LCDPins[0], LCDPins[1], LCDPins[2], LCDPins[3], LCDPins[4], LCDPins[5]);
    liquidCrystal.begin(16, 2);
    liquidCrystal.clear();
}

void LCD::display(String lines[2], bool lineIsEdited)
{
    static char mode;
    mode = lineIsEdited ? '*' : '>';
    
    liquidCrystal.clear();
    liquidCrystal.print(mode);
    liquidCrystal.print(lines[0]);
    liquidCrystal.setCursor(1, 1);
    liquidCrystal.print(lines[1]);
}