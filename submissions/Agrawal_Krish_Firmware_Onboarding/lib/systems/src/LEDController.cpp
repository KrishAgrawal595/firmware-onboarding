#include "LEDController.h"

void LEDController::init(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

unsigned long LEDController::calculateInterval(float temperature)
{
    // Clamp temperature within operational limits
    if (temperature <= BMEConstants::TEMP_MIN_C)
    {
        return BMEConstants::MAX_BLINK_INTERVAL_MS;
    }
    if (temperature >= BMEConstants::TEMP_MAX_C)
    {
        return BMEConstants::MIN_BLINK_INTERVAL_MS;
    }

    // Linear mapping calculation
    float factor = (temperature - BMEConstants::TEMP_MIN_C) / (BMEConstants::TEMP_MAX_C - BMEConstants::TEMP_MIN_C);
    return BMEConstants::MAX_BLINK_INTERVAL_MS - static_cast<unsigned long>(factor * (BMEConstants::MAX_BLINK_INTERVAL_MS - BMEConstants::MIN_BLINK_INTERVAL_MS));
}

void LEDController::update(float currentTemp, unsigned long currentMillis)
{
    unsigned long interval = calculateInterval(currentTemp);

    if (currentMillis - lastToggleTime >= interval)
    {
        lastToggleTime = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState ? HIGH : LOW);
    }
}