#include "Manager.hpp"

#include <iostream>

#include "Snake.hpp"
#include "Food.hpp"
#include "Map.hpp"

Manager::Manager() {
	m_map = new Map();
	m_food = new Food();

	m_snake = new Snake(sf::Vector2i(5, 10));
	m_snake->append(new Snake(sf::Vector2i(4, 10)));
	m_snake->append(new Snake(sf::Vector2i(3, 10)));

	m_snake->setFood(m_food);
	m_snake->setMap(m_map);
}

Manager::~Manager() {
	delete m_map;
	delete m_snake;
	delete m_food;
}

void Manager::update(float delta) {
	m_time += delta;

	if(m_time >= 100000.0f) {
		m_snake->update();
		m_time = 0.0f;
	}

	if(m_snake->isDead()) {
		delete m_snake;
	
		m_snake = new Snake(sf::Vector2i(5, 10));
		m_snake->append(new Snake(sf::Vector2i(4, 10)));
		m_snake->append(new Snake(sf::Vector2i(3, 10)));

		m_snake->setFood(m_food);
		m_snake->setMap(m_map);
	}
}

void Manager::draw(sf::RenderWindow & window) {
	m_map->draw(window);
	m_snake->draw(window);
	m_food->draw(window);
}

void Manager::onEvent(sf::Event & event) {
	if(event.type == sf::Event::KeyPressed) {
		switch(event.key.code) {
			case sf::Keyboard::Right:
				m_snake->setDirection(Right);
				break;
			case sf::Keyboard::Left:
				m_snake->setDirection(Left);
				break;
			case sf::Keyboard::Up:
				m_snake->setDirection(Up);
				break;
			case sf::Keyboard::Down:
				m_snake->setDirection(Down);
				break;
		}
	}
}
