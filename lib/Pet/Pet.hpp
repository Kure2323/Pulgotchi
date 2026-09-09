#pragma once

#include <Arduino.h>

constexpr uint16_t UPDATE_TIME = 5000;

enum class MOOD {
    NORMAL,
    HAPPY,
    SAD,
    ANGRY,
    HUNGRY,
    TIRED,
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
    uint8_t boredness = 0;

    void manageMood();

    public:
    uint8_t getSadness(); 
    uint8_t getHungry(); 
    uint8_t getAnger();
    uint8_t getTiredness();
    uint8_t getBoredness();

    void increaseSadness();
    void increaseHungry();
    void increaseAnger();
    void increaseTiredness();
    void increaseBoredness();

    void update();
};