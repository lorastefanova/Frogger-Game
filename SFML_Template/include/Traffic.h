#pragma once
#include <SFML./Graphics.hpp>

class Traffic
{
	/* Declaring */
public:
	float length;
	float speed;
	float posx;
	float posy;
	float getSpeed();
	
	sf::RectangleShape ObjectRectangle;

	sf::RectangleShape getObjectRectangle();

	sf::FloatRect getObjectBoundingBox();
	
	void moveObject(float speedIn);
	
	Traffic(float lengthIn, float posx, float posy, float speedIn, sf::Color coolorIn); // Constructor with adjustable parameters

	Traffic();
	~Traffic();
};

