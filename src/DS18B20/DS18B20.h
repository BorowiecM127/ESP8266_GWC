#ifndef DS18B20_H
#define DS18B20_H

#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>
#include "../Constants/Constants.h"

class DS18B20
{
public:
    DS18B20();
    ~DS18B20();

    void begin();
    void discoverDevices();
    float getTemperature(uint8_t deviceIndex);
    uint8_t GetDevicesCount();

private:
    void printDevicesNumber();
    void searchWireForAddress(int deviceNumber);
    void printDeviceAddress(DeviceAddress deviceAddress);

    OneWire oneWire;
    DallasTemperature sensors;
    DeviceAddress tempDeviceAddress;
    uint8_t devicesCount;
};

#endif