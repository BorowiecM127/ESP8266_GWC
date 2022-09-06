#ifndef GHESettings_H
#define GHESettings_H

#pragma once

class GHESettings
{
public:
    GHESettings();
    ~GHESettings();

    float AllTemperatures[3][2];

    float *Temperature1 = &AllTemperatures[0][0];
    float *WakeTemperature1 = &AllTemperatures[0][1];
    float *Temperature2 = &AllTemperatures[1][0];
    float *WakeTemperature2 = &AllTemperatures[1][1];
    float *TemperatureDelta1 = &AllTemperatures[2][0];
    float *TemperatureDelta2 = &AllTemperatures[2][1];

private:
};

#endif