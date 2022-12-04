#include "D1Robot.h"

D1Robot::D1Robot()
: screen(),
button()
{}

D1Robot::~D1Robot()
{}

D1Robot::D1Robot(const D1Robot &keypadShield)
: screen(keypadShield.screen),
button(keypadShield.button)
{}

D1Robot &D1Robot::operator=(const D1Robot &keypadShield)
{
    if (&keypadShield != this)
    {
        this->screen = keypadShield.screen;
        this->button = keypadShield.button;
    }

    return *this;
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