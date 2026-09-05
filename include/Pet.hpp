#pragma once

#include <Arduino.h>

#define UPDATE_TIME 5000

enum class MOOD {
    NORMAL,
    HAPPY,
    SAD,
    HUNGRY,
    BORED,
    RETARDED // Just in case i want to make something funnier
};

class Pet {
    private:
    uint32_t lastCheck = 0;

    MOOD actualMood = MOOD::NORMAL;
    uint8_t sadness = 0;
    uint8_t hungry = 0;
    uint8_t anger = 0;
    uint8_t tiredness = 0;

    public:
    uint8_t getSadness(); 
    uint8_t getHungry(); 
    uint8_t getAnger();
    uint8_t getTiredness();

    void update();
};