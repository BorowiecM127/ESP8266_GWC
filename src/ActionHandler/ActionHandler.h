#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#pragma once

#include <stdint.h>
#include <Arduino.h>

#define NONE_KEY 0
#define SELECT_KEY 1
#define LEFT_KEY 2
#define DOWN_KEY 3
#define UP_KEY 4
#define RIGHT_KEY 5

class ActionHandler
{
public:
    ActionHandler(uint8_t aPin);

    uint8_t GetKey();

private:
    uint8_t analogPin;
};

#endif