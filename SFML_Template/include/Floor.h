#pragma once
#include <SFML./Graphics.hpp>

class Floor
{
	/* Declaring */
public:

	sf::Texture FloorTexture;
	sf::Sprite FloorSprite;

	sf::Texture Floor2Texture;
	sf::Sprite Floor2Sprite;

	sf::Texture LeafTexture;
	sf::Sprite LeafSprite;

	sf::Texture WaterTexture;
	sf::Sprite WaterSprite;
	sf::RectangleShape WaterRectangle;

	sf::Sprite getFloor();
	sf::Sprite getFloor2();
	sf::Sprite getLeaf();
	sf::Sprite getWater();


	sf::RectangleShape Base1;
	sf::RectangleShape Base2;
	sf::RectangleShape Base3;
	sf::RectangleShape Base4;
	sf::RectangleShape Base5;

	sf::RectangleShape getBase1();
	sf::RectangleShape getBase2();
	sf::RectangleShape getBase3();
	sf::RectangleShape getBase4();
	sf::RectangleShape getBase5();

	sf::RectangleShape getWaterRectangle();

	sf::FloatRect getBase1BoundingBox();
	sf::FloatRect getBase2BoundingBox();
	sf::FloatRect getBase3BoundingBox();
	sf::FloatRect getBase4BoundingBox();
	sf::FloatRect getBase5BoundingBox();

	sf::FloatRect getWaterBoundingBox();


	Floor();
	~Floor();
};