#include "Line.h"

Line::Line()
{

}

Line::~Line()
{

}

String Line::GetLine()
{
    return title + String(value);
}