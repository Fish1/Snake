#include "Snake.hpp"

#include "define.hpp"

#include "Food.hpp"
#include "Map.hpp"

#include <iostream>

Snake::Snake(sf::Vector2i position) {
	m_position = position;
}

Snake::~Snake() {
	if(m_previous != nullptr) {
		delete m_previous;
	}
}

void Snake::update() {
	sf::Vector2i newPosition = m_position;

	switch(m_direction) {
		case Right:
			newPosition.x += 1;
		break;
		case Left:
			newPosition.x -= 1;
		break;
		case Up:
			newPosition.y -= 1;
		break;
		case Down:
			newPosition.y += 1;
		break;
	}

	crawl(newPosition);
}

void Snake::draw(sf::RenderWindow & renderWindow) {
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::White);
	rectangle.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	Snake * bodypart = this;

	do {
		rectangle.setPosition((BLOCK_SIZE + BLOCK_GAP) * bodypart->getX(), 
					(BLOCK_SIZE + BLOCK_GAP) * bodypart->getY());	
		renderWindow.draw(rectangle);
		bodypart = bodypart->m_previous;
	} while(bodypart != nullptr);
}

void Snake::append(Snake * snake) {
	Snake * current = this;
	while(current->m_previous != nullptr) {
		current = current->m_previous;
	}
	current->m_previous = snake;
	snake->m_next = current;
}

void Snake::crawl(sf::Vector2i newPosition) {
	Snake * index = this;
	
	/* Loop to the back */
	while(index->m_previous != nullptr) {
		index= index->m_previous;	
	}

	/* Extend if touching food */
	bool extend = ref_food->getPosition() == newPosition;
	if(extend == true) {
		append(new Snake(index->getPosition()));	
		ref_food->randomizePosition();
	}

	/* Loop to the front */
	while(index->m_next != nullptr) {
		index->setPosition(index->m_next->getPosition());
		
		/* If hit own body, end game */
		if(index->getPosition() == newPosition) {
			m_dead = true;
		}

		index = index->m_next;
	}

	index->setPosition(newPosition);

	/* If hit border, end game */
	if(ref_map->touchingBorder(getPosition())) {
		m_dead = true;
	}
}

void Snake::setDirection(Direction direction) {
	sf::Vector2i newPosition = m_position;
	switch(direction) {
		case Right:
			newPosition.x += 1;
		break;
		case Left:
			newPosition.x -= 1;
		break;
		case Up:
			newPosition.y -= 1;
		break;
		case Down:
			newPosition.y += 1;
		break;
	}

	sf::Vector2i prevPosition = m_previous->getPosition();
	
	if(newPosition == prevPosition) {

	} else {
		m_direction = direction;
	}
}

void Snake::setFood(Food * food) {
	ref_food = food;
}

void Snake::setMap(Map * map) {
	ref_map = map;
}

void Snake::setPrevious(Snake * previous) {
	m_previous = previous;
}

Snake * Snake::getPrevious() {
	return m_previous;
}

void Snake::setNext(Snake * next) {
	m_next = next;
}

Snake * Snake::getNext() {
	return m_next;
}

void Snake::setPosition(sf::Vector2i position) {
	m_position = position;
}

const sf::Vector2i & Snake::getPosition() {
	return m_position;
}

int Snake::getX() {
	return m_position.x;
}

int Snake::getY() {
	return m_position.y;
}

bool Snake::isDead() {
	return m_dead;
}
