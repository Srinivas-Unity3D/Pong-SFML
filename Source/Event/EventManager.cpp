#include "../../Header/Event/EventManager.h"

namespace Events 
{
	void EventManager::pollEvents(RenderWindow* game_window) 
	{
		Event event;
		while (game_window->pollEvent(event)) 
		{
			if (isKeyPressed(Keyboard::Escape))
			{
				game_window->close();
			}
		}
	}

	bool EventManager::isKeyPressed(Keyboard::Key key) 
	{
		
		return Keyboard::isKeyPressed(key);
	}
}