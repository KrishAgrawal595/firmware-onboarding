#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

BMEI2CInterface i2cInterface;
LEDController controller;

void setup()
{
    Serial.begin(115200);

    BMEI2CInterfaceInstance::create(i2cInterface);
    LEDControllerInstance::create(controller);

    LEDControllerInstance::instance().init();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("ERR: Could not find a valid BME280 sensor on I2C!");
        while (1);
    }
    Serial.println("BME280 I2C Interface initialized successfully.");
}

void loop()
{
    unsigned long currentMillis = millis();
    float temp = BMEI2CInterfaceInstance::instance().readTemperature();

    LEDControllerInstance::instance().update(temp, currentMillis);
}