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
    Category(const Category &category);
    Category &operator=(const Category &category);

    void setTemperatures(float temperatures[linesCount]);
    void setTemperatures(const float temperatures[linesCount]);
    
    void setTitles(String titles[linesCount]);
    void setTitles(const String titles[linesCount]);
    
    void setEditables(bool editables[linesCount]);
    void setEditables(const bool editables[linesCount]);

    String* getFormattedLines(int firstLineIndex);

    void incrementLineValue(uint8_t index, float value);
    void decrementLineValue(uint8_t index, float value);
    bool lineIsEditable(uint8_t index);

    String getLineTitle(uint8_t index);
    void setLineTitle(uint8_t index, String title);
    float getLineValue(uint8_t index);
    void setLineValue(uint8_t index, float value);
    bool getLineEditable(uint8_t index);
    void setLineEditable(uint8_t index, bool editable);

private:
    Line lines[linesCount];
};

#endif