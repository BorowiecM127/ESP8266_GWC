#include "GSD326.h"

GSD326::GSD326()
: referenceTimeMin(0), 
currentTimeCheckMin(off)
{
    this->statusPins.first = degrees5Pin;
    this->statusPins.second = degrees85Pin;
    this->setupActuator();
}

GSD326::~GSD326()
{}

GSD326::GSD326(const GSD326 &actuator)
: referenceTimeMin(actuator.referenceTimeMin), 
currentTimeCheckMin(actuator.currentTimeCheckMin),
statusPins(actuator.statusPins)
{}

GSD326 &GSD326::operator=(const GSD326 &actuator)
{
    if (&actuator != this)
    {
        this->referenceTimeMin = actuator.referenceTimeMin;
        this->currentTimeCheckMin = actuator.currentTimeCheckMin;
    }

    return *this;
}

void GSD326::begin() { 
    this->referenceTimeMin = this->getCurrentTimeMin();
}

void GSD326::handleCurrentState(Menu *menu) {
    this->handleCurrentPosition();
    this->handleElapsedTime(menu);
}

void GSD326::setupActuator()
{
    pinMode(triggerPin, OUTPUT);
    pinMode(rotationPin, OUTPUT);
    pinMode(statusPins.first, INPUT);
    pinMode(statusPins.second, INPUT);

    digitalWrite(triggerPin, ESP8266Low);
    digitalWrite(rotationPin, ESP8266Low);

    this->startRotation(!clockwise);

    while (digitalRead(statusPins.first) != ESP8266High || digitalRead(statusPins.second) != ESP8266High)
        delay(1000);

    this->turnOff();
}

void GSD326::handleCurrentPosition() {
    if ((digitalRead(statusPins.first) == ESP8266High && digitalRead(statusPins.second) == ESP8266High) || 
        (digitalRead(statusPins.first) == ESP8266Low && digitalRead(statusPins.second) == ESP8266Low))
        this->turnOff();
}

void GSD326::handleElapsedTime(Menu *menu) {
    unsigned long currentTimeMin = this->getCurrentTimeMin();
    unsigned long elapsedTime = this->getElapsedTime(this->referenceTimeMin, currentTimeMin);

    if (elapsedTime >= this->currentTimeCheckMin) {
        switch (this->currentTimeCheckMin) {
            case off:
                this->setupTemperatureCheck();
                break;
            case initial:
                this->performTemperatureCheck(menu);
                break;
            case on:
                this->performTemperatureCheck(menu);
                break;
        }
    }

    this->setReferenceTime(currentTimeMin);
}

void GSD326::setupTemperatureCheck() {
    #ifdef DEBUG
        Serial.println("Actuator will be opened");
    #endif

    this->startRotation(clockwise);
    this->currentTimeCheckMin = initial;
}

void GSD326::performTemperatureCheck(Menu *menu) {
    if (this->shouldRemainOpen(menu)) {
        #ifdef DEBUG
            Serial.println("Actuator will remain open");
        #endif
        
        this->currentTimeCheckMin = on;
    }
    else {
        #ifdef DEBUG
            Serial.println("Actuator will close");
        #endif
        
        this->startRotation(!clockwise);
        this->currentTimeCheckMin = off;
    }
}

void GSD326::setReferenceTime(unsigned long currentTimeMin) {
    this->referenceTimeMin = currentTimeMin;
}

void GSD326::startRotation(bool clockwise)
{
    this->setDirection(clockwise);
    this->turnOn();
}

void GSD326::setDirection(bool clockwise) {
    digitalWrite(rotationPin, clockwise);
}

void GSD326::turnOn() {
    digitalWrite(triggerPin, ESP8266High);
}

void GSD326::turnOff() {
    digitalWrite(triggerPin, ESP8266Low);
}

bool GSD326::shouldRemainOpen(Menu *menu) {
    return (
        menu->getTemperatureOutside() < menu->getWakeUpTemperatureLow() && 
        menu->getTemperatureInside() - menu->getTemperatureOutside() > menu->getDeltaTemperatureLow()
        ) || (
            menu->getTemperatureOutside() > menu->getWakeUpTemperatureHigh() && 
            menu->getTemperatureOutside() - menu->getTemperatureInside() > menu->getDeltaTemperatureHigh()
    );
}

unsigned long GSD326::getElapsedTime(unsigned long referenceTimeMin, unsigned long currentTimeMin) {
    if (referenceTimeMin > currentTimeMin)
        return this->getOverflowedTime(referenceTimeMin, currentTimeMin);
    else
        return currentTimeMin - referenceTimeMin;
}

unsigned long GSD326::getOverflowedTime(unsigned long referenceTimeMin, unsigned long currentTimeMin) {
    return ULONG_MAX - referenceTimeMin + currentTimeMin;
}

unsigned long GSD326::getCurrentTimeMin() { 
    return this->getCurrentTimeSec() / 60;
}

unsigned long GSD326::getCurrentTimeSec() { 
    return this->getCurrentTimeMs() / 1000;
}

unsigned long GSD326::getCurrentTimeMs() { 
    return millis();
}

