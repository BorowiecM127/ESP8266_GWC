#ifndef LINE_H
#define LINE_H

#pragma once

#include <Arduino.h>

class Line
{
public:
    Line();
    ~Line();
    Line(Line const &line);
    Line &operator=(Line const &line);

    String getFormattedLine();
    void incrementValue(float increment);
    void decrementValue(float decrement);
    bool isEditable();

    String getTitle();
    void setTitle(String title);
    float getValue();
    void setValue(float value);
    bool getEditable();
    void setEditable(bool editable);

private:
    String title;
    float value;
    bool editable;
};

#endif