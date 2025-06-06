#include "../../Header/Gameplay/GameplayManager.h"
#include "SFML/Graphics.hpp"

using namespace sf;

namespace Gameplay 
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		initialize();
		boundary = new Boundary();
		eventManager = manager;
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
	}

	void GameplayManager::update() 
	{
		player1->update(eventManager->isKeyPressed(Keyboard::W), eventManager->isKeyPressed(Keyboard::S));
		player2->update(eventManager->isKeyPressed(Keyboard::Up), eventManager->isKeyPressed(Keyboard::Down));
		ball->update(player1, player2);
	}
}