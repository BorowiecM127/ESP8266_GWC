#include "Line.h"

Line::Line()
: editable(false),
title(""),
value(0.0)
{}

Line::~Line()
{}

Line::Line(const Line &line)
: editable(line.editable),
title(line.title),
value(line.value)
{}

Line &Line::operator=(const Line &line)
{
    if (&line != this)
    {
        this->editable = line.editable;
        this->title = line.title;
        this->value = line.value;
    }
    
    return *this;
}

String Line::getFormattedLine()
{
    return this->title + String(this->value);
}

void Line::incrementValue(float increment)
{
    this->value += increment;
}

void Line::decrementValue(float decrement)
{
    this->value -= decrement;
}

bool Line::isEditable()
{
    return this->getEditable();
}

String Line::getTitle()
{
    return this->title;
}

void Line::setTitle(String title)
{
    this->title = title;
}

float Line::getValue()
{
    return this->value;
}

void Line::setValue(float value)
{
    this->value = value;
}

bool Line::getEditable()
{
    return this->editable;
}

void Line::setEditable(bool editable)
{
    this->editable = editable;
}