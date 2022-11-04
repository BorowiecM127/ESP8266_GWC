#ifndef ANALOGBUTTON_H
#define ANALOGBUTTON_H

#pragma once

#include "../../Constants/Constants.h"

class AnalogButton
{
public:
    AnalogButton();
    ~AnalogButton();

    void begin();
    analogKey readKey();

private:
    uint8_t keyPin;
};

#endif