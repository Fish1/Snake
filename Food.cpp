#include "Food.hpp"

#include <stdlib.h>
#include <iostream>

#include "define.hpp"

Food::Food() {
	randomizePosition();	
}

void Food::draw(sf::RenderWindow & renderWindow) {
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	rectangle.setPosition((BLOCK_SIZE + BLOCK_GAP) * m_position.x,
	(BLOCK_SIZE + BLOCK_GAP) * m_position.y);
	renderWindow.draw(rectangle);
}

void Food::randomizePosition() {
	int randX = (rand() % MAP_SIZE) + 1;
	int randY = (rand() % MAP_SIZE) + 1;
	m_position = sf::Vector2i(randX, randY);

	Snake * index = ref_snake;
	while(index != nullptr) {
		if(getPosition() == index->getPosition()) {
			std::cout << "TRY AGAIN" << std::endl;
			randomizePosition();
			break;
		}

		index = index->getPrevious();
	}
}

void Food::setSnake(Snake * snake) {
	ref_snake = snake;
}

const sf::Vector2i & Food::getPosition() {
	return m_position;
}
