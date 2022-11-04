#include "Menu.h"

Menu::Menu(): lineIsEdited(false)
{

}

Menu::~Menu()
{

}

void Menu::begin()
{
    setTemperatures(defaultTemperatures);
    setTitles(defaultTitles);
    setEditables(defaultEditables);
}

void Menu::setTemperatures(float temperatures[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setTemperatures(temperatures[i]);
}

void Menu::setTemperatures(const float temperatures[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setTemperatures(temperatures[i]);
}

void Menu::setTitles(String titles[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setTitles(titles[i]);
}

void Menu::setTitles(const String titles[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setTitles(titles[i]);
}

void Menu::setEditables(bool editables[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setEditables(editables[i]);
}

void Menu::setEditables(const bool editables[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].setEditables(editables[i]);
}

String *Menu::getActiveCategory()
{
    return categories[activeCategory].getFormattedLines(activeLine);
}

bool Menu::getLineIsEdited()
{
    return lineIsEdited;
}

void Menu::handlePressedButton(analogKey pressedKey)
{
    switch (pressedKey)
    {
        case upKey:
            handleUpKey();
            break;
        case downKey:
            handleDownKey();
            break;
        case leftKey:
            handleLeftKey();
            break;
        case rightKey:
            handleRightKey();
            break;
        case selectKey:
            handleSelection();
            break;
        default:
            break;
    }
}

void Menu::setPreviousLine()
{
    activeLine = abs((activeLine - 1) % linesCount);
}

void Menu::setNextLine()
{
    activeLine = (activeLine + 1) % linesCount;
}

void Menu::setPreviousCategory()
{
    activeCategory = abs((activeCategory - 1) % categoriesCount);
}

void Menu::setNextCategory()
{
    activeCategory = (activeCategory + 1) % categoriesCount;
}

void Menu::handleUpKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].incrementLineValue(activeLine, fineModifierValue);
    }
    else
    {
        setPreviousLine();
    }
}

void Menu::handleDownKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].decrementLineValue(activeLine, fineModifierValue);
    }
    else
    {
        setNextLine();
    }
}

void Menu::handleLeftKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].decrementLineValue(activeLine, coarseModifierValue);
    }
    else
    {
        activeLine = 0;
        setPreviousCategory();
    }
}

void Menu::handleRightKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].incrementLineValue(activeLine, coarseModifierValue);
    }
    else
    {
        activeLine = 0;
        setNextCategory();
    }
}

void Menu::handleSelection()
{
    if (categories[activeCategory].lineIsEditable(activeLine))
    {
        lineIsEdited = !lineIsEdited;
    }
}

void Menu::updateSensorTemperatures(DS18B20 *sensors, uint8_t refreshDivider)
{
    if (loopCounter % refreshDivider == 0)
    {
        loopCounter = 0;
        readAllTemperatures(sensors);
    }

    ++loopCounter;
}

void Menu::readAllTemperatures(DS18B20 *sensors)
{
    uint8_t temperatureSensorCount = 0;

    for (uint8_t i = 0; i < categoriesCount; ++i)
    {
        for (uint8_t j = 0; j < linesCount; ++j)
        {
            if (!categories[i].lineIsEditable(j))
            {
                categories[i].setLineValue(j, sensors->getTemperature(temperatureSensorCount));
                ++temperatureSensorCount;
            }
        }
    }
}