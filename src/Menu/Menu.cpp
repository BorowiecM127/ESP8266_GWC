#include "Menu.h"

Menu::Menu()
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
            SetPreviousLine();
            break;
        case downKey:
            SetNextLine();
            break;
        case leftKey:
            SetPreviousCategory();
            break;
        case rightKey:
            activeLine = 0;
            SetNextCategory();
            break;
        case selectKey:
            activeLine = 0;
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

void Menu::HandleSelection()
{

}