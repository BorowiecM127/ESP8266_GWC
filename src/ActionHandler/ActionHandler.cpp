#include "ActionHandler.h"

ActionHandler::ActionHandler(uint8_t aPin) : analogPin(aPin) {}

uint8_t ActionHandler::GetKey()
{
    int buttonValue = analogRead(analogPin);

    if (buttonValue > 550)
        return NONE_KEY;
    if (buttonValue > 500)
        return SELECT_KEY;
    if (buttonValue > 400)
        return LEFT_KEY;
    if (buttonValue > 300)
        return DOWN_KEY;
    if (buttonValue > 150)
        return UP_KEY;
    if (buttonValue < 50)
        return RIGHT_KEY;
}