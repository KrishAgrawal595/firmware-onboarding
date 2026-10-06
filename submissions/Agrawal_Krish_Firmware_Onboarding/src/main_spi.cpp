#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"

BMESPIInterface spiInterface;
LEDController controller;

void setup()
{
    Serial.begin(115200);

    BMESPIInterfaceInstance::create(spiInterface);
    LEDControllerInstance::create(controller);

    LEDControllerInstance::instance().init();

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println("no valid BME280 sensor on SPI");
        while (1);
    }
    Serial.println("BME280 SPI Interface successful.");
}

void loop()
{
    unsigned long currentMillis = millis();
    float temp = BMESPIInterfaceInstance::instance().readTemperature();

    LEDControllerInstance::instance().update(temp, currentMillis);
}