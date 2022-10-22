#ifndef MENU_H
#define MENU_H

#pragma once

#include "Category/Category.h"
#include "../Constants/Constants.h"
#include "../Pair/Pair.h"
#include "../DS18B20/DS18B20.h"

class Menu
{
public:
    Menu();
    ~Menu();

    void Init();

    void SetTemperatures(float temperatures[categoriesCount][linesCount]);
    void SetTemperatures(const float temperatures[categoriesCount][linesCount]);

    void SetTitles(String titles[categoriesCount][linesCount]);
    void SetTitles(const String titles[categoriesCount][linesCount]);

    void SetEditables(bool editables[categoriesCount][linesCount]);
    void SetEditables(const bool editables[categoriesCount][linesCount]);
    
    String* GetActiveCategory();
    void HandlePressedButton(analogKey categoryNumber);

    void UpdateSensorTemperatures(DS18B20 *sensors, uint8_t refreshDivider);

    Category categories[categoriesCount];
    uint8_t activeCategory;
    uint8_t activeLine;
    bool lineIsEdited;
    
private:
    void SetPreviousLine();
    void SetNextLine();
    void SetPreviousCategory();
    void SetNextCategory();

    void HandleUpKey();
    void HandleDownKey();
    void HandleLeftKey();
    void HandleRightKey();
    void HandleSelection();

    void ReadAllTemperatures(DS18B20 *sensors);

    uint8_t loopCounter = 0;
};

#endif