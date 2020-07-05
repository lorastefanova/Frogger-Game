#include "Frog.h"
#include <iostream>

using namespace std;

void Frog::initFrog() 
{	// Frog default position
	x = 350;
	y = 550;
	// Frog starts with 3 lives
	lives = 3;

	// Creating the frog
	FrogRectangle.setSize(sf::Vector2f(50.0f, 50.0f));
	FrogRectangle.setPosition(350, 550);
	FrogRectangle.setFillColor(sf::Color::Transparent);

	FrogTexture.loadFromFile(".\\assets\\textures\\tex.png");
	FrogSprite.setTexture(FrogTexture);
	FrogSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	FrogSprite.setPosition(350, 550);
}

Frog::Frog()
{
	initFrog();
}


Frog::~Frog()
{
}


void Frog::moveUp() // Frog movement function
{
	cout << "The Frog moves up." << endl;
	if (y > 50) // If statement so the frog doesn't go off the screen
	{
		y = y - 50;
		FrogSprite.setPosition(x, y);
		FrogRectangle.setPosition(x, y);
	}
}

void Frog::moveDown() // Frog movement function
{
	cout << "The Frog moves down." << endl;
	if (y < 550) // If statement so the frog doesn't go off the screen
	{
		y = y + 50;
		FrogSprite.setPosition(x, y);
		FrogRectangle.setPosition(x, y);
	}

}

void Frog::moveLeft() // Frog movement function
{
	cout << "The Frog moves left." << endl;
	if (x > 0) // If statement so the frog doesn't go off the screen
	{
		x = x - 50;
		FrogSprite.setPosition(x, y);
		FrogRectangle.setPosition(x, y);
	}
}

void Frog::moveRight() // Frog movement function
{
	cout << "The Frog moves right." << endl;
	if (x < 700) // If statement so the frog doesn't go off the screen
	{
		x = x + 50;
		FrogSprite.setPosition(x, y);
		FrogRectangle.setPosition(x, y);
	}
}

void  Frog::FrogRespawn() // Reset frog's position (Respawns frog)
{
	x = 350;
	y = 550;
	FrogSprite.setPosition(x, y);
	FrogRectangle.setPosition(x, y);
}

void Frog::RideLog(float speedIn) // Frog moves on logs with their different speeds
{
	FrogSprite.move(speedIn, 0.0f);
	FrogRectangle.move(speedIn, 0.0f);
	if (FrogRectangle.getPosition().x > 700) // If statement so the frog doesn't go off the screen
	{
		FrogRectangle.setPosition(700, FrogRectangle.getPosition().y);
		FrogSprite.setPosition(700, FrogRectangle.getPosition().y);

	}
	else if (FrogRectangle.getPosition().x < 0) // If statement so the frog doesn't go off the screen
	{
		FrogRectangle.setPosition(0, FrogRectangle.getPosition().y);
		FrogSprite.setPosition(0, FrogRectangle.getPosition().y);
	}
	x = FrogRectangle.getPosition().x; // Frog Position Updated
	y = FrogRectangle.getPosition().y;
}

sf::Sprite Frog::getFrog() // Function to get the frog sprite
{
	return FrogSprite;
}

sf::RectangleShape Frog::getFrogRectangle() // Function to get the frog rectangle
{
	return FrogRectangle;
}

sf::FloatRect Frog::getFrogBoundingBox() // Function to get collision
{
	return FrogRectangle.getGlobalBounds();
}