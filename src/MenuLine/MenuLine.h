#ifndef MENULINE_H
#define MENULINE_H

#pragma once

#include <Arduino.h>

class MenuLine
{
public:
    MenuLine();
    ~MenuLine();
    
    String StringValue();

    String Title;
    float Value;
private:
};

#endif