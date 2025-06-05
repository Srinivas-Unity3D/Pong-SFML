#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize() 
	{
		game_window = new RenderWindow();
		CreateGameWindow();
	}

	void GameWindowManager::CreateGameWindow()
	{
		game_window->create(
			VideoMode::getDesktopMode(),
			game_title,
			Style::Fullscreen
		);
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}

	bool GameWindowManager::isGameRunning() 
	{
		return game_window->isOpen();
	}

	void GameWindowManager::render() 
	{
		game_window->clear(Color(200, 50, 50, 255));
		game_window->display();
	}
}