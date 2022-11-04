#include "D1Robot.h"

D1Robot::D1Robot()
{

}

D1Robot::~D1Robot()
{

}

void D1Robot::begin()
{
    screen.begin();
    button.begin();
}

void D1Robot::updateScreen(String lines[2], bool lineIsEdited)
{
    screen.display(lines, lineIsEdited);
}

analogKey D1Robot::readAnalogButton()
{
    return button.readKey();
}