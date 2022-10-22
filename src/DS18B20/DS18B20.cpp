#include "DS18B20.h"

DS18B20::DS18B20()
{

}

DS18B20::~DS18B20()
{

}

void DS18B20::begin()
{
    oneWire = OneWire(oneWirePin);
    sensors = DallasTemperature(&oneWire);
    sensors.begin();
}

void DS18B20::discoverDevices()
{
    devicesCount = sensors.getDeviceCount();
    printDevicesNumber();

    for (int i = 0; i < devicesCount; i++)
    {
        searchWireForAddress(i);
    }
}

void DS18B20::printDevicesNumber()
{
    Serial.println("Locating devices...");
    Serial.print("Found ");
    Serial.print(devicesCount, DEC);
    Serial.println(" devices.");
}

void DS18B20::searchWireForAddress(int deviceNumber)
{
    if (sensors.getAddress(tempDeviceAddress, deviceNumber))
    {
        Serial.print("Found device ");
        Serial.print(deviceNumber, DEC);
        Serial.print(" with address: ");
        printDeviceAddress(tempDeviceAddress);
        Serial.println();
    }
    else
    {
        Serial.print("Found ghost device at ");
        Serial.print(deviceNumber, DEC);
        Serial.println(" but could not detect address. Check power and cabling");
    }
}

void DS18B20::printDeviceAddress(DeviceAddress deviceAddress)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (deviceAddress[i] < 16)
            Serial.print("0");
        Serial.print(deviceAddress[i], HEX);
    }
}

float DS18B20::getTemperature(uint8_t deviceIndex)
{
    sensors.requestTemperatures();

    if (sensors.getAddress(tempDeviceAddress, deviceIndex))
    {
        return sensors.getTempC(tempDeviceAddress);
    }
    else
    {
        Serial.print("Can't get temperature for device: ");
        Serial.println(deviceIndex, DEC);

        return -127;
    }
}

uint8_t DS18B20::GetDevicesCount()
{
    return devicesCount;
}