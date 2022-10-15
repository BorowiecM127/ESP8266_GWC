#ifndef ANALOGBUTTON_H
#define ANALOGBUTTON_H

#pragma once

#include "../../Constants/Constants.h"

class AnalogButton
{
public:
    AnalogButton();
    ~AnalogButton();

    void Init();
    analogKey ReadKey();

private:
    uint8_t keyPin;
};

#endif