#pragma once

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Pet.hpp>

enum class SCREEN {
    MAIN,
    APP
};

class UI {
    private:
    Adafruit_SSD1306& display;
    Pet copy; // To contrast. Need to search for other solutions

    void draw(SCREEN screen);

    public:
    void update();

};