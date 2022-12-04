#include "src/Constants/Constants.h"
#include "src/Menu/Menu.h"
#include "src/GSD326/GSD326.h"

#ifdef DEBUG
    #include "src/GSD326/Tests/Tests.h"
#else
    #include "src/D1Robot/D1Robot.h"
    #include "src/DS18B20/DS18B20.h"
#endif

Menu menu;
GSD326 actuator;

#ifdef DEBUG
    Tests tests(&menu, &actuator);
#else
    DS18B20 temperatureSensors;
    D1Robot keypadShield;
#endif

void setup()
{
    Serial.begin(serialBaudRate);

    menu.begin();
    actuator.begin();

    #ifdef DEBUG
        tests.runAllTests();
    #else
        keypadShield.begin();
        temperatureSensors.begin();
    #endif
}

void loop()
{
    #ifndef DEBUG
        menu.updateSensorTemperatures(&temperatureSensors, refreshDivider);
        keypadShield.updateScreen(menu.getActiveCategory(), menu.getLineIsEdited());
        menu.handlePressedButton(keypadShield.readAnalogButton());
        actuator.handleCurrentState(&menu);
        delay(loopDelayMs);
    #endif
}
