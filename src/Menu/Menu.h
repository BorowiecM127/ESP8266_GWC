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

    void begin();

    void setTemperatures(float temperatures[categoriesCount][linesCount]);
    void setTemperatures(const float temperatures[categoriesCount][linesCount]);

    void setTitles(String titles[categoriesCount][linesCount]);
    void setTitles(const String titles[categoriesCount][linesCount]);

    void setEditables(bool editables[categoriesCount][linesCount]);
    void setEditables(const bool editables[categoriesCount][linesCount]);
    
    String* getActiveCategory();
    bool getLineIsEdited();

    void handlePressedButton(analogKey categoryNumber);
    void updateSensorTemperatures(DS18B20 *sensors, uint8_t refreshDivider);
    
private:
    void setPreviousLine();
    void setNextLine();
    void setPreviousCategory();
    void setNextCategory();

    void handleUpKey();
    void handleDownKey();
    void handleLeftKey();
    void handleRightKey();
    void handleSelection();

    void readAllTemperatures(DS18B20 *sensors);

    Category categories[categoriesCount];
    uint8_t activeCategory;
    uint8_t activeLine;
    bool lineIsEdited;
    uint8_t loopCounter = 0;
};

#endif