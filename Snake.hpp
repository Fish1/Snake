#ifndef SNAKEHPP
#define SNAKEHPP

#include <SFML/Graphics.hpp>
#include "define.hpp"

class Food;
class Map;

class Snake {
private:
	Direction m_direction = Right;
	sf::Vector2i m_position;

	Food * ref_food = nullptr;
	Map * ref_map = nullptr;

	Snake * m_next = nullptr;
	Snake * m_previous = nullptr;

	bool m_dead = false;

public:
	Snake(sf::Vector2i position);
	~Snake();

	void update();
	void draw(sf::RenderWindow & renderWindow);

	void append(Snake * snake);

	void crawl(sf::Vector2i newPosition);
	void setDirection(Direction direction);

	void setFood(Food * food);
	void setMap(Map * map);

	void setPrevious(Snake * previous);
	Snake * getPrevious();

	void setNext(Snake * next);
	Snake * getNext();

	void setPosition(sf::Vector2i position);
	const sf::Vector2i & getPosition();
	int getX();
	int getY();

	bool isDead();
};

#endif
