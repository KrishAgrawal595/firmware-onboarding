#include "BMESPIInterface.h"

bool BMESPIInterface::begin(uint8_t csPin)
{
    return bme.begin(csPin);
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}