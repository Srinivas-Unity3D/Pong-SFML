#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "../Event/EventManager.h"
#include "../Boundary/Boundary.h"
#include "../Utility/TimeService.h"

using namespace Events;
using namespace Utility;


namespace Gameplay 
{
	class GameplayManager 
	{
	private:
		//left
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;
		
		//right
		float player2_postion_x = 1210.0f;
		float player2_postion_y = 300.0f;
		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		void initialize();

		EventManager* eventManager;

		Boundary* boundary;
	public:
		TimeService* time_service;
		GameplayManager(EventManager* eventManager);
		void render(RenderWindow* game_window);
		void update();

	};
}
