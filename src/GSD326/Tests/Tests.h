#ifndef TESTS_H
#define TESTS_H

#pragma once

#include "../../Constants/Constants.h"

#ifdef DEBUG

#include "../../Menu/Menu.h"
#include "../../D1Robot/D1Robot.h"
#include "../../GSD326/GSD326.h"

/*
Test cases:
- t_in does not change after actuator opening:
    - t_out < tw_low && t_in - t_out > dT_low
    - t_out < tw_low && t_in - t_out < dT_low
    - t_out > tw_high && t_out - t_in > dT_high
    - t_out > tw_high && t_out - t_in < dT_high
    - t_out < tw_high && t_out > tw_low
- t_in changes after actuator opening:
    - t_out < tw_low && t_in - t_out > dT_low => t_out < tw_low && t_in - t_out < dT_low
    - t_out > tw_high && t_out - t_in > dT_high => t_out > tw_high && t_out - t_in < dT_high
*/

class Tests
{
public:
    Tests(Menu *menu, GSD326 *actuator);
    ~Tests();

    void runAllTests();
    
    void testCase_tempLowerLimitExceeded_deltaLimitExceeded_notChangesLater();
    void testCase_tempHigherLimitExceeded_deltaLimitExceeded_notChangesLater();
    void tempLimitNotExceeded_deltaLimitNotExceeded_notChangesLater();
    void tempLowerLimitExceeded_deltaLimitNotExceeded_notChangesLater();
    void tempHigherLimitExceeded_deltaLimitNotExceeded_notChangesLater();
    void tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta();
    void tempHigherLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta();

private:
    void tempLimitExceeded_deltaLimitExceeded_notChangesLater(float temperatureIn, float temperatureOut);
    void tempLimitExceededOrNot_deltaLimitNotExceeded_notChangesLater(float temperatureIn, float temperatureOut);
    void tempLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta(float temperatureIn, float temperatureOut, float newTemperatureIn);

    void setTemperatures(float t1);
    void setTemperatures(float t1, float t2);
    void performInitialStateHandling();
    void handleCurrentStateWithDelay(int timeSec, float tempIn);
    void handleCurrentStateWithDelay(int timeSec);
    void resetToDefaultState();
    void waitSecAndPrint(unsigned long timeSec);

    float testTemperatures[categoriesCount][linesCount];

    Menu *menu;
    GSD326 *actuator;

    static const unsigned long msInSec = 1000;
    static const unsigned long timeExceedingInitActuatorStateSec = 61;
    static const unsigned long timeExceedingOnActuatorStateSec = 121;
    static const unsigned long timeForActuatorShutdownSec = 61;
};

#endif  //DEBUG
#endif  //TESTS_H