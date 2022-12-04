#include "Category.h"

Category::Category()
: lines()
{}

Category::~Category()
{}

Category::Category(const Category &category)
{
    for (int i = 0; i < linesCount; ++i)
        this->lines[i] = category.lines[i];
}

Category &Category::operator=(const Category &category)
{
    if (&category != this)
        for (int i = 0; i < linesCount; ++i)
            this->lines[i] = category.lines[i];

    return *this;
}

void Category::setTemperatures(float temperatures[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setValue(temperatures[i]);
}

void Category::setTemperatures(const float temperatures[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setValue(temperatures[i]);
}

void Category::setTitles(String titles[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setTitle(titles[i]);
}

void Category::setTitles(const String titles[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setTitle(titles[i]);
}

void Category::setEditables(bool editables[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setEditable(editables[i]);
}

void Category::setEditables(const bool editables[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].setEditable(editables[i]);
}

String *Category::getFormattedLines(int firstLineIndex)
{
    if (firstLineIndex < linesCount)
    {
        static String outputLines[linesCount];

        for (int i = firstLineIndex; i < (firstLineIndex + linesCount); ++i)
        {
            outputLines[i - firstLineIndex] = lines[i % linesCount].getFormattedLine();
        }

        return outputLines;
    }
}

void Category::incrementLineValue(uint8_t index, float value)
{
    if (index > 0 && index < linesCount)
    {
        lines[index].incrementValue(value);
    }
}

void Category::decrementLineValue(uint8_t index, float value)
{
    if (index > 0 && index < linesCount)
    {
        lines[index].decrementValue(value);
    }
}

bool Category::lineIsEditable(uint8_t index)
{
    return this->lines[index].isEditable();
}

String Category::getLineTitle(uint8_t index)
{
    return this->lines[index].getTitle();
}

void Category::setLineTitle(uint8_t index, String title)
{
    this->lines[index].setTitle(title);
}

float Category::getLineValue(uint8_t index)
{
    return this->lines[index].getValue();
}

void Category::setLineValue(uint8_t index, float value)
{
    this->lines[index].setValue(value);
}

bool Category::getLineEditable(uint8_t index)
{
    return this->lines[index].getEditable();
}

void Category::setLineEditable(uint8_t index, bool editable)
{
    this->lines[index].setEditable(editable);
}
