#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../Gameplay/GameplayManager.h"

using namespace sf;
using namespace Core;
using namespace Events;
using namespace std;
using namespace Gameplay;

namespace Core
{
	class GameLoop
	{
	private:
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
		GameplayManager* game_play_manager;

	public:
		void initialize();

		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}