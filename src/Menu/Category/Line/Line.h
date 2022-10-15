#ifndef LINE_H
#define LINE_H

#pragma once

#include <Arduino.h>

class Line
{
public:
    Line();
    ~Line();

    String GetLine();

    String title;
    float value;
    bool editable;
};

#endif