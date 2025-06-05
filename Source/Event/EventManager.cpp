#include "../../Header/Event/EventManager.h"
#include <iostream>

namespace Events 
{
	void EventManager::pollEvents(RenderWindow* game_window) 
	{
		Event event;
		while (game_window->pollEvent(event)) 
		{
			if (isKeyPressed(Keyboard::Escape) || (event.type == Event::Closed))
			{
				game_window->close();
			}

			if (isLeftMouseClicked()) 
			{
				Vector2i position = Mouse::getPosition();

				std::cout << "Left mouse clicked at: " << position.x << "," << position.y << std::endl;
			}
		}
	}

	bool EventManager::isKeyPressed(Keyboard::Key key) 
	{
		
		return Keyboard::isKeyPressed(key);
	}

	bool EventManager::isLeftMouseClicked() 
	{
		return Mouse::isButtonPressed(Mouse::Left);
	}
}