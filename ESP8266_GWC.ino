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

    menu.begin();
    keypadShield.begin();
    temperatureSensors.begin();
}

void loop()
{
    menu.updateSensorTemperatures(&temperatureSensors, refreshDivider);
    keypadShield.updateScreen(menu.getActiveCategory(), menu.getLineIsEdited());
    menu.handlePressedButton(keypadShield.readAnalogButton());

    delay(loopDelayMs);
}