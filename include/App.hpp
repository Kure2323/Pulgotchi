#pragma once

#include <Arduino.h>


class App {

    private:
    unsigned appSprite;

    public:
    void runApp();
    void goBack();
    ~App();
    
};