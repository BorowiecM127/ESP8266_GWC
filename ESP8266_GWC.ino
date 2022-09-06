#include "src/ScreenHandler/ScreenHandler.h"
#include "src/GHESettings/GHESettings.h"

const uint8_t LCDPins[6] = {D1, D2, D4, D5, D6, D7};
const uint8_t analogPin = A0;

const uint8_t menuCategoriesCount = 3;
const uint8_t menuCategoryElements = 2;

const String menuTitles[menuCategoriesCount][menuCategoryElements] = {
    {"T. 1: ",
     "T. 2: "},
    {"Tw. 1: ",
     "Tw. 2: "},
    {"Dt. 1: ",
     "Dt. 2: "}};

const Pair<uint8_t, uint8_t> menuDimensions(menuCategoriesCount, menuCategoryElements);

ScreenHandler screen;
String menuLines[menuCategoriesCount][menuCategoryElements];
GHESettings gheSettings;

void setup()
{
    Serial.begin(9600);

    *gheSettings.Temperature1 = 15.0; // getting temp from ds18b20
    *gheSettings.Temperature2 = 20.0; // getting temp from ds18b20
    *gheSettings.WakeTemperature1 = 10.0;
    *gheSettings.WakeTemperature2 = 30.0;
    *gheSettings.TemperatureDelta1 = 5.0;
    *gheSettings.TemperatureDelta2 = 5.0;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            menuLines[i][j] = menuTitles[i][j] + String(gheSettings.AllTemperatures[i][j], 1);
        }
    }

    screen.Init(LCDPins, analogPin, menuDimensions);
}

void loop()
{
    screen.Update(menuLines);
    // Serial.println(10);
    // Each menuLine should be cleared
    delay(200);
}
