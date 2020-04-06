#ifndef FOODHPP
#define FOODHPP

#include <SFML/Graphics.hpp>

#include "Snake.hpp"

class Food {
private:
	sf::Vector2i m_position;

	Snake * ref_snake = nullptr;
public:
	Food();	
	
	void update();
	void draw(sf::RenderWindow & renderWindow);

	void setSnake(Snake * snake);

	void randomizePosition();

	const sf::Vector2i & getPosition();
};

#endif
