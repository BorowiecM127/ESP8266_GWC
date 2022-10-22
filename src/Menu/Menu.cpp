#include "Menu.h"

Menu::Menu(): lineIsEdited(false)
{

}

Menu::~Menu()
{

}

void Menu::Init()
{
    SetTemperatures(defaultTemperatures);
    SetTitles(defaultTitles);
    SetEditables(defaultEditables);
}

void Menu::SetTemperatures(float temperatures[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetTemperatures(temperatures[i]);
}

void Menu::SetTemperatures(const float temperatures[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetTemperatures(temperatures[i]);
}

void Menu::SetTitles(String titles[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetTitles(titles[i]);
}

void Menu::SetTitles(const String titles[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetTitles(titles[i]);
}

void Menu::SetEditables(bool editables[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetEditables(editables[i]);
}

void Menu::SetEditables(const bool editables[categoriesCount][linesCount])
{
    for (int i = 0; i < categoriesCount; ++i)
        categories[i].SetEditables(editables[i]);
}

String *Menu::GetActiveCategory()
{
    return categories[activeCategory].GetLines(activeLine);
}

void Menu::HandlePressedButton(analogKey pressedKey)
{
    switch (pressedKey)
    {
        case upKey:
            HandleUpKey();
            break;
        case downKey:
            HandleDownKey();
            break;
        case leftKey:
            HandleLeftKey();
            break;
        case rightKey:
            HandleRightKey();
            break;
        case selectKey:
            HandleSelection();
            break;
        default:
            break;
    }
}

void Menu::SetPreviousLine()
{
    activeLine = abs((activeLine - 1) % linesCount);
}

void Menu::SetNextLine()
{
    activeLine = (activeLine + 1) % linesCount;
}

void Menu::SetPreviousCategory()
{
    activeCategory = abs((activeCategory - 1) % categoriesCount);
}

void Menu::SetNextCategory()
{
    activeCategory = (activeCategory + 1) % categoriesCount;
}

void Menu::HandleUpKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].lines[activeLine].value += 0.5;
    }
    else
    {
        SetPreviousLine();
    }
}

void Menu::HandleDownKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].lines[activeLine].value -= 0.5;
    }
    else
    {
        SetNextLine();
    }
}

void Menu::HandleLeftKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].lines[activeLine].value -= 1.0;
    }
    else
    {
        activeLine = 0;
        SetPreviousCategory();
    }
}

void Menu::HandleRightKey()
{
    if (lineIsEdited)
    {
        categories[activeCategory].lines[activeLine].value += 1.0;
    }
    else
    {
        activeLine = 0;
        SetNextCategory();
    }
}

void Menu::HandleSelection()
{
    if (categories[activeCategory].lines[activeLine].editable)
    {
        lineIsEdited = !lineIsEdited;
    }
}

void Menu::UpdateSensorTemperatures(DS18B20 *sensors, uint8_t refreshDivider)
{
    if (loopCounter % refreshDivider == 0)
    {
        loopCounter = 0;
        ReadAllTemperatures(sensors);
    }

    ++loopCounter;
}

void Menu::ReadAllTemperatures(DS18B20 *sensors)
{
    uint8_t temperatureSensorCount = 0;

    for (uint8_t i = 0; i < categoriesCount; ++i)
    {
        for (uint8_t j = 0; j < linesCount; ++j)
        {
            if (!categories[i].lines[j].editable)
            {
                categories[i].lines[j].value = sensors->getTemperature(temperatureSensorCount);
                ++temperatureSensorCount;
            }
        }
    }
}