#include <SFML./Graphics.hpp>
#include "Traffic.h"
#include <string>

Traffic::Traffic(float lengthIn, float posx, float posy, float speedIn, sf::Color colorIn)
{
	// Creating car/log with adjustable parameters
	speed = speedIn;
	ObjectRectangle.setSize(sf::Vector2f(lengthIn, 50.0f));
	ObjectRectangle.setPosition(posx, posy);
	ObjectRectangle.setFillColor(colorIn);
}

Traffic::Traffic()
{

}

Traffic::~Traffic()
{

}

sf::RectangleShape Traffic::getObjectRectangle() // Function to get the object rectangle
{
	return ObjectRectangle;
}

sf::FloatRect Traffic::getObjectBoundingBox() // Function to get collision
{
	return ObjectRectangle.getGlobalBounds();
}

void Traffic::moveObject(float speedIn) // Function to move the car/log at different speeds
{
	ObjectRectangle.move(speedIn, 0.0f);
	if (ObjectRectangle.getPosition().x < -150.0f) // If statement to reset the position of the cars/logs
	{
		ObjectRectangle.setPosition(750, ObjectRectangle.getPosition().y);
	}
	else if (ObjectRectangle.getPosition().x > 750.0f) // If statement to reset the position of the cars/logs
	{
		ObjectRectangle.setPosition(-150, ObjectRectangle.getPosition().y);
	}
}

float Traffic::getSpeed() // Function to get speed of the car/log
{
	return speed;
}