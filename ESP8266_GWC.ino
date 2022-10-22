#include "src/Menu/Menu.h"
#include "src/D1Robot/D1Robot.h"
#include "src/DS18B20/DS18B20.h"
#include "src/Constants/Constants.h"

Menu menu;
D1Robot keypadShield;
DS18B20 temperatureSensors;

void setup()
{
    Serial.begin(serialBaudRate);

    menu.Init();
    keypadShield.Init();
    temperatureSensors.begin();
}

void loop()
{
    menu.UpdateSensorTemperatures(&temperatureSensors, refreshDivider);
    keypadShield.UpdateScreen(menu.GetActiveCategory(), menu.lineIsEdited);
    menu.HandlePressedButton(keypadShield.ReadAnalogButton());

    delay(loopDelayMs);
}