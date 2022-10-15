#include "src/Menu/Menu.h"
#include "src/D1Robot/D1Robot.h"
#include "src/DS18B20/DS18B20.h"
#include "src/Constants/Constants.h"

String LCDLines[2];
Menu menu;
D1Robot keypadShield;
DS18B20 temperatures[2];

void setup()
{
    Serial.begin(9600);

    menu.Init();
    keypadShield.Init();
}

void loop()
{
    keypadShield.UpdateScreen(menu.GetActiveCategory());
    menu.HandlePressedButton(keypadShield.ReadAnalogButton());

    delay(200);
}