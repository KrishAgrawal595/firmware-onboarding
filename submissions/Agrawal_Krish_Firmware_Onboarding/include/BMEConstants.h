#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // Pin Definitions
    constexpr uint8_t LED_PIN = 13;
    constexpr uint8_t BME_CS_PIN = 10;

    // Default I2C Address
    constexpr uint8_t BME_I2C_ADDR = 0x76;

    // Blink Interval Bounds (milliseconds)
    constexpr unsigned long MIN_BLINK_INTERVAL_MS = 100;  // High temperature limit
    constexpr unsigned long MAX_BLINK_INTERVAL_MS = 1000; // Low temperature limit

    constexpr float TEMP_MIN_C = 20.0f;
    constexpr float TEMP_MAX_C = 40.0f;
}