#include "Map.hpp"
#include "define.hpp"

#include <iostream>

Map::Map() {
	m_rectangle = new sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
}

Map::~Map() {
	delete m_rectangle;
}

void Map::draw(sf::RenderWindow & renderWindow) {
	m_rectangle->setFillColor(sf::Color::Red);
	for(unsigned int y = 0; y <= MAP_SIZE + 1; ++y) {
	for(unsigned int x = 0; x <= MAP_SIZE + 1; ++x) {
		if(x == 0 || y == 0 || x == MAP_SIZE + 1 || y == MAP_SIZE + 1) {
			m_rectangle->setPosition(x * (BLOCK_SIZE + BLOCK_GAP), 
					y * (BLOCK_SIZE + BLOCK_GAP));
			renderWindow.draw(*m_rectangle);
		}
	}}
}

bool Map::touchingBorder(const sf::Vector2i & position) {
	int x = position.x;
	int y = position.y;
	return x == 0 || x == MAP_SIZE + 1 || y == 0 || y == MAP_SIZE + 1;	
}
