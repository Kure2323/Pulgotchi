#pragma once

#include <Arduino.h>

#include <ButtonHandler.hpp>


class App {
private:
    ButtonHandler& button_handler;
    bool isGoBackBlocked { false };
    void goBack();


public:
    App(ButtonHandler& button_handler);
    ~App();
    void update();
};


