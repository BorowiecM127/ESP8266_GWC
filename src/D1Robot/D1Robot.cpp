#include "D1Robot.h"

D1Robot::D1Robot()
{

}

D1Robot::~D1Robot()
{

}

void D1Robot::Init()
{
    screen.Init();
    button.Init();
}

void D1Robot::UpdateScreen(String lines[2])
{
    screen.Display(lines);
}

analogKey D1Robot::ReadAnalogButton()
{
    return button.ReadKey();
}