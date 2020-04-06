#ifndef MANAGERHPP
#define MANAGERHPP

#include <SFML/Graphics.hpp>

class Snake;
class Food;
class Map;

class Manager {
private:
	Snake * m_snake = nullptr;
	Food * m_food = nullptr;
	Map * m_map = nullptr;

	float m_time = 0;

public:
	Manager();
	~Manager(); 

	void update(float delta);
	void draw(sf::RenderWindow & window);
	void onEvent(sf::Event & event);
};

#endif
