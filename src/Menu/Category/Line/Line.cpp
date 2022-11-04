#include "Line.h"

Line::Line()
{

}

Line::~Line()
{

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