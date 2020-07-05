#include <SFML./Graphics.hpp>
#include <iostream>
#include "Floor.h"

Floor::Floor()
{
	// Creating first safe zone
	FloorTexture.loadFromFile(".\\assets\\textures\\tile.png");
	FloorTexture.setRepeated(true);
	FloorSprite.setTexture(FloorTexture);
	FloorSprite.setTextureRect(sf::IntRect(0, 0, 750, 50));
	FloorSprite.setPosition(0, 550);

	// Creating second safe zone 
	Floor2Texture.loadFromFile(".\\assets\\textures\\tile.png");
	Floor2Texture.setRepeated(true);
	Floor2Sprite.setTexture(Floor2Texture);
	Floor2Sprite.setTextureRect(sf::IntRect(0, 0, 750, 50));
	Floor2Sprite.setPosition(0, 300);

	// Creating frog base sprite
	LeafTexture.loadFromFile(".\\assets\\textures\\leaf.png");
	LeafTexture.setRepeated(true);
	LeafSprite.setTexture(LeafTexture);
	LeafSprite.setTextureRect(sf::IntRect(0, 0, 750, 100));
	LeafSprite.setPosition(0, 0);

	// Creating the water sprite
	WaterTexture.loadFromFile(".\\assets\\textures\\water.png");
	WaterTexture.setRepeated(true);
	WaterSprite.setTexture(WaterTexture);
	WaterSprite.setTextureRect(sf::IntRect(0, 0, 800, 300));
	WaterSprite.setPosition(0, 50);

	// Creating water rectangle
	WaterRectangle.setSize(sf::Vector2f(750.0f, 250.0f));
	WaterRectangle.setPosition(0, 50);
	WaterRectangle.setFillColor(sf::Color::Transparent);

	// Creating frog bases rectangles
	Base1.setSize(sf::Vector2f(50.0f, 50.0f));
	Base1.setPosition(50, 50);
	Base1.setFillColor(sf::Color::Transparent);

	Base2.setSize(sf::Vector2f(50.0f, 50.0f));
	Base2.setPosition(200, 50);
	Base2.setFillColor(sf::Color::Transparent);

	Base3.setSize(sf::Vector2f(50.0f, 50.0f));
	Base3.setPosition(350, 50);
	Base3.setFillColor(sf::Color::Transparent);

	Base4.setSize(sf::Vector2f(50.0f, 50.0f));
	Base4.setPosition(500, 50);
	Base4.setFillColor(sf::Color::Transparent);

	Base5.setSize(sf::Vector2f(50.0f, 50.0f));
	Base5.setPosition(650, 50);
	Base5.setFillColor(sf::Color::Transparent);
}


Floor::~Floor()
{

}

/* Functions to get the safe zones sprites */
sf::Sprite Floor::getFloor() 
{
	return FloorSprite;
}

sf::Sprite Floor::getFloor2()
{
	return Floor2Sprite;
}


sf::Sprite Floor::getLeaf() // Function to get the base sprite
{
	return LeafSprite;
}

sf::Sprite Floor::getWater() // Function to get the water sprite
{
	return WaterSprite;
}

sf::RectangleShape Floor::getWaterRectangle() // Function to get the water rectangle
{
	return WaterRectangle;
}

sf::FloatRect Floor::getWaterBoundingBox() // Function to get the water collision
{
	return WaterRectangle.getGlobalBounds();
}


/* Functions to get bases and collision */
sf::RectangleShape Floor::getBase1()
{
	return Base1;
}

sf::FloatRect Floor::getBase1BoundingBox()
{
	return Base1.getGlobalBounds();
}


sf::RectangleShape Floor::getBase2()
{
	return Base2;
}

sf::FloatRect Floor::getBase2BoundingBox()
{
	return Base2.getGlobalBounds();
}


sf::RectangleShape Floor::getBase3()
{
	return Base3;
}

sf::FloatRect Floor::getBase3BoundingBox()
{
	return Base3.getGlobalBounds();
}


sf::RectangleShape Floor::getBase4()
{
	return Base4;
}

sf::FloatRect Floor::getBase4BoundingBox()
{
	return Base4.getGlobalBounds();
}


sf::RectangleShape Floor::getBase5()
{
	return Base5;
}

sf::FloatRect Floor::getBase5BoundingBox()
{
	return Base5.getGlobalBounds();
}