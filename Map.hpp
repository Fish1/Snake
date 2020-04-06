#ifndef MAPHPP
#define MAPHPP

#include <SFML/Graphics.hpp>

class Map {
private:
	sf::RectangleShape * m_rectangle;

public:
	Map();
	~Map();

	void draw(sf::RenderWindow & window);	
	bool touchingBorder(const sf::Vector2i & position);
};

#endif
