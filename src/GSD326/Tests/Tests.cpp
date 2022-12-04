#include "Tests.h"

#ifdef DEBUG

Tests::Tests(Menu *menu, GSD326 *actuator)
{
    this->menu = menu;
    this->actuator = actuator;
    for (int i = 0; i < categoriesCount; ++i)
        for (int j = 0; j < linesCount; ++j)
            this->testTemperatures[i][j] = defaultTemperatures[i][j];
}

Tests::~Tests()
{}

void Tests::runAllTests() {
    unsigned long allTestStart = millis();
    unsigned long singleTestStart;
    unsigned long singleTestStop;

    Serial.println();
    Serial.println("Tests are starting");
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting testCase_tempLowerLimitExceeded_deltaLimitExceeded_notChangesLater()");
    singleTestStart = millis();
    this->testCase_tempLowerLimitExceeded_deltaLimitExceeded_notChangesLater();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting testCase_tempHigherLimitExceeded_deltaLimitExceeded_notChangesLater()");
    singleTestStart = millis();
    this->testCase_tempHigherLimitExceeded_deltaLimitExceeded_notChangesLater();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting tempLimitNotExceeded_deltaLimitNotExceeded_notChangesLater()");
    singleTestStart = millis();
    this->tempLimitNotExceeded_deltaLimitNotExceeded_notChangesLater();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting tempLowerLimitExceeded_deltaLimitNotExceeded_notChangesLater()");
    singleTestStart = millis();
    this->tempLowerLimitExceeded_deltaLimitNotExceeded_notChangesLater();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting tempHigherLimitExceeded_deltaLimitNotExceeded_notChangesLater()");
    singleTestStart = millis();
    this->tempHigherLimitExceeded_deltaLimitNotExceeded_notChangesLater();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta()");
    singleTestStart = millis();
    this->tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
    
    Serial.println("Starting tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta()");
    singleTestStart = millis();
    this->tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta();
    singleTestStop = millis();
    Serial.print("Test time [sec]: ");
    Serial.println((singleTestStop - singleTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();

    Serial.print("All tests time [sec]: ");
    Serial.println((singleTestStop - allTestStart) / 1000);
    Serial.println("==================================================================================");
    Serial.println();
}

void Tests::testCase_tempLowerLimitExceeded_deltaLimitExceeded_notChangesLater() {
    tempLimitExceeded_deltaLimitExceeded_notChangesLater(3.0, -10.0);
}

void Tests::testCase_tempHigherLimitExceeded_deltaLimitExceeded_notChangesLater() {
    tempLimitExceeded_deltaLimitExceeded_notChangesLater(26.0, 32.0);
}

void Tests::tempLimitNotExceeded_deltaLimitNotExceeded_notChangesLater() {
    this->tempLimitExceededOrNot_deltaLimitNotExceeded_notChangesLater(11.0, 15.0);
}

void Tests::tempLowerLimitExceeded_deltaLimitNotExceeded_notChangesLater() {
    this->tempLimitExceededOrNot_deltaLimitNotExceeded_notChangesLater(-6.0, -10.0);
}

void Tests::tempHigherLimitExceeded_deltaLimitNotExceeded_notChangesLater() {
    this->tempLimitExceededOrNot_deltaLimitNotExceeded_notChangesLater(26.0, 30.0);
}

void Tests::tempLowerLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta() {
    tempLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta(3.0, -10.0, -6.0);
}

void Tests::tempHigherLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta() {
    tempLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta(26.0, 32.0, 28.0);
}

void Tests::tempLimitExceeded_deltaLimitExceeded_notChangesLater(float temperatureIn, float temperatureOut) {
    this->setTemperatures(temperatureIn, temperatureOut);

    this->performInitialStateHandling();
    this->handleCurrentStateWithDelay(timeExceedingInitActuatorStateSec);
    this->handleCurrentStateWithDelay(timeExceedingOnActuatorStateSec);
    this->resetToDefaultState();
}

void Tests::tempLimitExceededOrNot_deltaLimitNotExceeded_notChangesLater(float temperatureIn, float temperatureOut) {
    this->setTemperatures(temperatureIn, temperatureOut);

    this->performInitialStateHandling();
    this->handleCurrentStateWithDelay(timeExceedingInitActuatorStateSec);
    this->waitSecAndPrint(timeForActuatorShutdownSec);
}

void Tests::tempLimitExceeded_deltaLimitExceeded_tempInChangesLaterToBeBelowDelta(float temperatureIn, float temperatureOut, float newTemperatureIn) {
    this->setTemperatures(temperatureIn, temperatureOut);

    this->performInitialStateHandling();
    this->handleCurrentStateWithDelay(timeExceedingInitActuatorStateSec);
    this->handleCurrentStateWithDelay(timeExceedingOnActuatorStateSec, newTemperatureIn);
    this->waitSecAndPrint(timeForActuatorShutdownSec);
}

void Tests::setTemperatures(float t1) {
    this->setTemperatures(t1, this->testTemperatures[0][1]);
}

void Tests::setTemperatures(float t1, float t2) {
    this->testTemperatures[0][0] = t1;
    this->testTemperatures[0][1] = t2;

    Serial.print("Temperature 1 is set to: ");
    Serial.println(testTemperatures[0][0]);
    Serial.print("Temperature 2 is set to: ");
    Serial.println(testTemperatures[0][1]);
}

void Tests::performInitialStateHandling() {
    this->menu->setTemperatures(this->testTemperatures);
    this->actuator->handleCurrentState(this->menu);
}

void Tests::handleCurrentStateWithDelay(int timeSec, float tempIn) {
    this->setTemperatures(tempIn);
    this->handleCurrentStateWithDelay(timeSec);
}

void Tests::handleCurrentStateWithDelay(int timeSec) {
    this->waitSecAndPrint(timeSec);

    this->menu->setTemperatures(testTemperatures);
    this->actuator->handleCurrentState(menu);
}

void Tests::resetToDefaultState() {
    Serial.println("Resetting actuator to default state (waiting period for ON state, then waiting for actuator close)");
    this->setTemperatures(10.0, 15.0);
    this->waitSecAndPrint(timeExceedingOnActuatorStateSec);

    this->menu->setTemperatures(testTemperatures);
    this->actuator->handleCurrentState(menu);
    this->waitSecAndPrint(timeForActuatorShutdownSec);
}

void Tests::waitSecAndPrint(unsigned long timeSec) {
    Serial.print("Waiting ");
    Serial.print(timeSec);
    Serial.println(" sec");
    delay(timeSec * msInSec);
}

#endif  //DEBUG