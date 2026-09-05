#include "Pet.hpp"
#include <Arduino.h>

// Public
uint8_t Pet::getSadness() {
    return sadness;
};

uint8_t Pet::getHungry() {
    return hungry;
};

uint8_t Pet::getAnger() {
    return anger;
};

uint8_t Pet::getTiredness() {
    return tiredness;
};

void Pet::update() {
    {
        unsigned long now = millis();
        if (now - lastCheck < UPDATE_TIME) {
            return;
        }
        lastCheck = now;
    }

    const uint8_t maxValue = 255;
    const uint8_t addValue = 51;

    // Chaos
    if (random(10000) == 0) {
        sadness = 255;
        hungry = 255;
        anger = 255;
        tiredness = 255;
    }

    if (sadness != maxValue && random(10) == 0) {
        sadness += addValue;
    }

    if (hungry != maxValue && random(10) == 0) {
        hungry += addValue;
    }

    if (anger != maxValue && random(20) == 0) {
        anger += addValue;
    }

    if (tiredness != maxValue && random(10) == 0) {
        tiredness += addValue;
    }

    Serial.print("Sadness=");
    Serial.println(sadness);

    Serial.print("Hungry=");
    Serial.println(hungry);

    Serial.print("Anger=");
    Serial.println(anger);

    Serial.print("Tiredness=");
    Serial.println(tiredness);

    Serial.println('\n');
}
