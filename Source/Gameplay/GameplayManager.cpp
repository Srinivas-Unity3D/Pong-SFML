#include "../../Header/Gameplay/GameplayManager.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace Utility;

namespace Gameplay 
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service = new TimeService();
		time_service->initialize();

		initialize();
		boundary = new Boundary();
		eventManager = manager;
		ui_service = new UIService;
	}

	void GameplayManager::initialize() 
	{
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_postion_x, player2_postion_y);
	}

	void GameplayManager::render(RenderWindow* game_window) 
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}

	void GameplayManager::update() 
	{
		time_service->update();

		player1->update(eventManager->isKeyPressed(Keyboard::W), eventManager->isKeyPressed(Keyboard::S), time_service);
		player2->update(eventManager->isKeyPressed(Keyboard::Up), eventManager->isKeyPressed(Keyboard::Down), time_service);
		ball->update(player1, player2, time_service);
	}
}