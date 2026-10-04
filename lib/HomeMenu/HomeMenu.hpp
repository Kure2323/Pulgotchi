#pragma once

#include <App.hpp>
#include <vector>

class HomeMenu {

private:
    std::vector<App> games;
    uint8_t selectedGame { 0 };
    std::vector<App> apps;
    uint8_t selectedApp { 0 };

    App* runningApp = nullptr;
    ButtonHandler* button_handler = nullptr;

    bool showMenu = true;

public:
    HomeMenu();
    void giveControl(ButtonHandler* button_handler);
    HomeMenu(std::vector<App> _games, std::vector<App> apps);
    ~HomeMenu();
    void openApp(App* app);
    void closeApp();
    void update();
};
