#include <iostream>
#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <time.h>

#include "Manager.hpp"
#include "define.hpp"

int main(void) {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(512, 512), "Snake");
	sf::View view = sf::View(sf::FloatRect(BLOCK_GAP / -2.0f, BLOCK_GAP / -2.0f, 
			(BLOCK_SIZE + BLOCK_GAP) * (MAP_SIZE + 2), 
			(BLOCK_SIZE + BLOCK_GAP) * (MAP_SIZE + 2)));
	window.setView(view);
	sf::Clock clock;
	sf::Event event;

	Manager * manager = new Manager();

	while(window.isOpen()) {

		/* Check Events */
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			} else {
				manager->onEvent(event);
			}
		}

		/* Update Game Loop */
		window.clear();
		manager->update(clock.restart().asMicroseconds());
		manager->draw(window);
		window.display();
	}

	delete manager;
	return 0;
}
