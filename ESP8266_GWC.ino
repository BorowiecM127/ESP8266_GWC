#include "src/ScreenHandler/ScreenHandler.h"
#include "src/GHESettings/GHESettings.h"
#include "src/MenuLine/MenuLine.h"

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
MenuLine menuLines[menuCategoriesCount][menuCategoryElements];
GHESettings gheSettings;

void setup()
{
    Serial.begin(9600);

    setDefaultTemperatures();

    initializemenuLines();

    bool **editablePositions = new bool *[menuDimensions.first]();
    initializeMenuPositions(editablePositions, &menuDimensions);

    screen.Init(LCDPins, analogPin, menuDimensions, editablePositions);
}

void loop()
{
    screen.Update(menuLines);
    // Serial.println(10);
    // Each menuLine should be cleared
    delay(200);
}

void setDefaultTemperatures()
{
    *gheSettings.Temperature1 = 15.0; // temp from ds18b20
    *gheSettings.Temperature2 = 20.0; // temp from ds18b20
    *gheSettings.WakeTemperature1 = 10.0;
    *gheSettings.WakeTemperature2 = 30.0;
    *gheSettings.TemperatureDelta1 = 5.0;
    *gheSettings.TemperatureDelta2 = 5.0;
}

void initializemenuLines()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            menuLines[i][j].Title = menuTitles[i][j];
            menuLines[i][j].Value = gheSettings.AllTemperatures[i][j];
        }
    }
}

void initializeMenuPositions(bool **editablePositions, const Pair<uint8_t, uint8_t> *menuDimensions)
{
    for (int i = 0; i < menuDimensions->first; ++i)
    {
        editablePositions[i] = new bool[menuDimensions->second]();
    }

    for (int i = 0; i < menuDimensions->first; i++)
    {
        for (int j = 0; j < menuDimensions->second; ++j)
        {
            if (i == 0 && (j == 0 || j == 1)) // pierwsze dwie pozycje w menu - t1 i t2 czytane z czujnika
                editablePositions[i][j] = false;
            else
                editablePositions[i][j] = true;
        }
    }
}
