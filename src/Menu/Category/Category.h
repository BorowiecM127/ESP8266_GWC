#ifndef CATEGORY_H
#define CATEGORY_H

#pragma once

#include "../../Constants/Constants.h"
#include "Line/Line.h"

class Category
{
public:
    Category();
    ~Category();

    void SetTemperatures(float temperatures[linesCount]);
    void SetTemperatures(const float temperatures[linesCount]);
    
    void SetTitles(String titles[linesCount]);
    void SetTitles(const String titles[linesCount]);
    
    void SetEditables(bool editables[linesCount]);
    void SetEditables(const bool editables[linesCount]);

    String* GetLines(int firstLineIndex);

    Line lines[linesCount];
};

#endif