#include "AnalogButton.h"

AnalogButton::AnalogButton()
{

}

AnalogButton::~AnalogButton()
{

}

void AnalogButton::begin()
{
    keyPin = analogPin;
}

analogKey AnalogButton::readKey()
{
    int buttonValue = analogRead(keyPin);

    if (buttonValue > 550)
        return noneKey;
    if (buttonValue > 500)
        return selectKey;
    if (buttonValue > 400)
        return leftKey;
    if (buttonValue > 300)
        return downKey;
    if (buttonValue > 150)
        return upKey;
    if (buttonValue < 50)
        return rightKey;
}