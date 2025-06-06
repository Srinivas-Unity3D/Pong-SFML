#include "../../Header/Core/GameLoop.h"
#include <SFML/Graphics.hpp>

using namespace sf;


namespace Core
{
	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();

		game_window_manager->initialize();
	}

	bool GameLoop::isGameRunning()
	{
		return game_window_manager->isGameRunning();
	}

	void GameLoop::pollEvent()
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());
	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();
		game_window_manager->displayGameWindow();
	}

	void GameLoop::update()
	{
		
	}
}