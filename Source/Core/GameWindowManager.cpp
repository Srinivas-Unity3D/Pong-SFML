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
			VideoMode(game_window_width, game_window_height),
			game_title,
			Style::Default
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

	void GameWindowManager::clearGameWindow() 
	{
		//game_window->clear(Color(200, 50, 50, 255)); // if want red window uncomment it
	}

	void GameWindowManager::displayGameWindow()
	{
		game_window->display();
	}
}