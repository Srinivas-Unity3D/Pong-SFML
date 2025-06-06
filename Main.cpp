#include <iostream>
#include "Header/Core/GameLoop.h"

using namespace Core;

int main()
{
    GameLoop* game_window_manager = new GameLoop();
    game_window_manager->initialize();


    while (game_window_manager->isGameRunning())
    {
        game_window_manager->pollEvent();
        game_window_manager->update();
        game_window_manager->render();
    }

    return 0;
}