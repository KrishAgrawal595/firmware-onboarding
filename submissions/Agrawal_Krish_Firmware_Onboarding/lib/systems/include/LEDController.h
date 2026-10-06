#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void init(uint8_t pin = BMEConstants::LED_PIN);
    void update(float currentTemp, unsigned long currentMillis);

private:
    uint8_t ledPin = BMEConstants::LED_PIN;
    bool ledState = false;
    unsigned long lastToggleTime = 0;

    unsigned long calculateInterval(float temperature);
};

using LEDControllerInstance = etl::singleton<LEDController>;