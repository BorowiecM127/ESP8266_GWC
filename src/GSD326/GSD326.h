#ifndef GSD326_H
#define GSD326_H

#pragma once

#include <limits.h>
#include "../Constants/Constants.h"
#include "../Menu/Menu.h"
#include "../Pair/Pair.h"

class GSD326
{
public:
    GSD326();
    ~GSD326();
    GSD326(const GSD326 &actuator);
    GSD326 &operator=(const GSD326 &actuator);

    void begin();
    void handleCurrentState(Menu *menu);

private:
    void setupActuator();
    void handleCurrentPosition();
    void handleElapsedTime(Menu *menu);

    void setupTemperatureCheck();
    void performTemperatureCheck(Menu *menu);
    
    void setReferenceTime(unsigned long currentTimeMin);
    void startRotation(bool clockwise);
    void setDirection(bool clockwise);
    void turnOn();
    void turnOff();

    bool shouldRemainOpen(Menu* menu);

    unsigned long getElapsedTime(unsigned long referenceTimeMin, unsigned long currentTimeMin);
    unsigned long getOverflowedTime(unsigned long referenceTimeMin, unsigned long currentTimeMin);
    unsigned long getCurrentTimeMin();
    unsigned long getCurrentTimeSec();
    unsigned long getCurrentTimeMs();

    unsigned long referenceTimeMin;
    actuatorCheckTimeMin currentTimeCheckMin;
    Pair<uint8_t, uint8_t> statusPins;
};

#endif