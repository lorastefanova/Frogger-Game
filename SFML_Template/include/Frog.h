#pragma once
#include <SFML./Graphics.hpp>

class Frog
{
	/* Declaring */
public: 
	int x;
	int y;
	int lives;

	sf::RectangleShape FrogRectangle;
	sf::Texture FrogTexture;
	sf::Sprite FrogSprite;

	sf::Sprite getFrog();
	sf::RectangleShape getFrogRectangle();

	sf::FloatRect getFrogBoundingBox();

	Frog();
	~Frog();

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

	void FrogRespawn();

	void initFrog();

	void RideLog(float speed);
};
