#include "Category.h"

Category::Category()
{

}

Category::~Category()
{

}

void Category::SetTemperatures(float temperatures[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].value = temperatures[i];
}

void Category::SetTemperatures(const float temperatures[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].value = temperatures[i];
}

void Category::SetTitles(String titles[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].title = titles[i];
}

void Category::SetTitles(const String titles[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].title = titles[i];
}

void Category::SetEditables(bool editables[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].editable = editables[i];
}

void Category::SetEditables(const bool editables[linesCount])
{
    for (int i = 0; i < linesCount; ++i)
        lines[i].editable = editables[i];
}

String *Category::GetLines(int firstLineIndex)
{
    if (firstLineIndex < linesCount)
    {
        static String outputLines[linesCount];

        for (int i = firstLineIndex; i < (firstLineIndex + linesCount); ++i)
        {
            outputLines[i - firstLineIndex] = lines[i % linesCount].GetLine();
        }

        return outputLines;
    }
    else
    {
        // throw exception
    }
}