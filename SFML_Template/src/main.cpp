#include <SFML/Graphics.hpp>
#include <iostream>
#include "Frog.h"
#include "Floor.h"
#include "Traffic.h"
#include<vector>

using namespace std;

// Create a window with the constructor
sf::RenderWindow window(sf::VideoMode(750, 600), "The Frogger Game by Lora");

/* Declaring */
int maxCars = 10;
int maxLogs = 8;
float length = 100.0;
float posx = 0;
float posy = 500;
bool isExit = false;


Frog player;
Floor flr;
Traffic traffic;

sf::Font font;

vector<Traffic> allCars;
vector<Traffic> allLogs;

void initMe()
{
	font.loadFromFile(".\\assets\\fonts\\BRITANIC.ttf"); // Loads font

	window.setFramerateLimit(60); // Set fps


	for (int i = 0; i < maxCars; i++) // Generating cars in vector with different parameters each
	{

		if (i < 3)
		{

			allCars.push_back(Traffic(70.0, 0, 500, 5.0, sf::Color::Red));

		}
		else if (i < 6)
		{

			allCars.push_back(Traffic(150.0, 0, 450, -6.0, sf::Color::Blue));

		}
		else if (i < 8)
		{

			allCars.push_back(Traffic(100.0, 0, 400, 8.0, sf::Color::Magenta));

		}
		else if (i < 10)
		{

			allCars.push_back(Traffic(50.0, 0, 350, -7.0, sf::Color::Yellow));

		}
	}

	for (int j = 0; j < maxLogs; j++) // Genarating logs in vector with different parameters each
	{

		if (j > 1 && j <= 2)
		{

			allLogs.push_back(Traffic(200.0, 0, 100, 1.0, sf::Color(139, 69, 19)));

		}
		else if (j > 3 && j <= 4)
		{

			allLogs.push_back(Traffic(150.0, 0, 150, -1.0, sf::Color(160, 82, 45)));

		}
		else if (j > 5 && j <= 6)
		{

			allLogs.push_back(Traffic(100.0, 0, 200, 2.0, sf::Color(139, 69, 19)));

		}
		else if (j > 6 && j <= 8)
		{

			allLogs.push_back(Traffic(150.0, 0, 250, -2.0, sf::Color(160, 82, 45)));

		}
	}

} // initMe()


bool isQuit() // Function for quit or repeat the game
{
	cout << "Quit? [Y/N]" << endl;
	char yn;
	do
	{
		cin >> yn;
		yn = toupper(yn);
		if (yn == 'Y')
		{
			return true;
		}
		else if (yn == 'N')
		{
			player.initFrog();
			return false;
		}

	} while (!(yn == 'Y' || yn == 'N'));

} // isQuit()

void displayMe() // Function with drawables
{
	if (flr.WaterSprite.getPosition().x > 0)  // Water animation
		flr.WaterSprite.setPosition(-50, 0);

	// Frog lives
	sf::Text lives("Lives: ", font);
	lives.setCharacterSize(30);
	lives.setStyle(sf::Text::Bold);
	lives.setFillColor(sf::Color::Black);
	lives.setPosition(0, 0);

	// Current number of lives
	sf::Text numLives(to_string(player.lives), font);
	numLives.setFont(font);
	numLives.setCharacterSize(30);
	numLives.setStyle(sf::Text::Bold);
	numLives.setFillColor(sf::Color::Black);
	numLives.setPosition(100, 0);

	window.clear(sf::Color::Black); // Clear window

	// Draw to the window  
	window.draw(flr.getFloor());
	window.draw(flr.getWater());
	window.draw(flr.getWaterRectangle());
	window.draw(flr.getFloor2());
	window.draw(flr.getLeaf());
	window.draw(flr.getBase1());
	window.draw(flr.getBase2());
	window.draw(flr.getBase3());
	window.draw(flr.getBase4());
	window.draw(flr.getBase5());


	for (int i = 0; i < allCars.size(); i++)  // Draw vector of cars
	{
		window.draw(allCars.at(i).getObjectRectangle());
	}

	for (int j = 0; j < allLogs.size(); j++) // Draw vector of logs
	{
		window.draw(allLogs.at(j).getObjectRectangle());
	}

	window.draw(player.getFrogRectangle());
	window.draw(player.getFrog());
	window.draw(lives);
	window.draw(numLives);

	// Display what is drawn
	window.display();

} // displayMe()

int main()
{
	initMe();

	// Run until the user closes the window
	while (window.isOpen())
	{
		// Check all the user events
		sf::Event event;

		while (window.pollEvent(event))
		{
			// User has pressed the close button

			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}

			// Frog movement
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					player.moveUp(); // Up
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					player.moveDown(); // Down
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					player.moveLeft(); // Left
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					player.moveRight(); // Right
				}
			}
		}

		// Cars collision
		for (int i = 0; i < allCars.size(); i++)
		{
			if (player.getFrogBoundingBox().intersects(allCars.at(i).getObjectBoundingBox())) // If frog collides with a car
			{
				player.FrogRespawn(); // Respawn the frog
				cout << "Frog died by a car." << endl;
				player.lives--; // -1 life

				if (player.lives < 1) // If frog is out of lives
				{
					displayMe(); // Reset the game
					cout << "Game Finish?" << endl;
					isExit = isQuit(); // Ask to quit or repeat
					break;
				}
			}
		}

		// Logs collision
		bool onLog = false;
		int onWhichLog;
		sf::FloatRect FrogHitBox = player.FrogRectangle.getGlobalBounds();
		sf::FloatRect WaterHitBox = flr.WaterRectangle.getGlobalBounds();
		if (FrogHitBox.intersects(WaterHitBox)) // If frog collides with water
		{
			for (int j = 0; j < allLogs.size(); j++)
			{
				sf::FloatRect LogHitbox = allLogs.at(j).ObjectRectangle.getGlobalBounds();
				if (FrogHitBox.intersects(LogHitbox)) // If frog collides with log
				{
					onLog = true; // Frog is on a log
					onWhichLog = j;
				}
			}

			if (onLog == true) // If frog is on a log
			{
				cout << "Frog on log" << endl;
				player.RideLog(allLogs.at(onWhichLog).getSpeed()); // Frog moves with the speed & direction of log
			}
			else // If frog is not on a log
			{
				cout << "Frog died in water." << endl;
				player.FrogRespawn(); // Respawns the frog
				player.lives--; // -1 life

				if (player.lives < 1) // If frog is out of lives
				{
					displayMe(); // Reset the game
					cout << "Game Finish?" << endl;
					isExit = isQuit(); // Ask to quit or repeat
					
				}
			}
		}
		/* If frog goes to one of the bases*/
		if (FrogHitBox.intersects(flr.getBase1BoundingBox()) ||
			FrogHitBox.intersects(flr.getBase2BoundingBox()) ||
			FrogHitBox.intersects(flr.getBase3BoundingBox()) ||
			FrogHitBox.intersects(flr.getBase4BoundingBox()) ||
			FrogHitBox.intersects(flr.getBase5BoundingBox()))
		{
			cout << "You won!" << endl;
			cout << "Game Finish?" << endl;
			displayMe(); // Reset the game
			isExit = isQuit(); // Ask to quit or repeat
		}

		// Moving cars
		for (int i = 0; i < allCars.size(); i++)
		{
			if (i < 3)
			{
				allCars.at(i).moveObject(allCars.at(i).getSpeed());
			}
			else if (i < 6)
			{
				allCars.at(i).moveObject(allCars.at(i).getSpeed());
			}
			else if (i < 8)
			{
				allCars.at(i).moveObject(allCars.at(i).getSpeed());
			}
			else if (i < 10)
			{
				allCars.at(i).moveObject(allCars.at(i).getSpeed());
			}
		}

		// Moving logs
		for (int j = 0; j < allLogs.size(); j++)
		{
			if (j < 3)
			{
				allLogs.at(j).moveObject(allLogs.at(j).getSpeed());
			}
			else if (j < 6)
			{
				allLogs.at(j).moveObject(allLogs.at(j).getSpeed());
			}
			else if (j < 8)
			{
				allLogs.at(j).moveObject(allLogs.at(j).getSpeed());
			}
			else if (j < 10)
			{
				allLogs.at(j).moveObject(allLogs.at(j).getSpeed());
			}
		}

		flr.WaterSprite.move(1.0f, 0.0f); // Water animation

		displayMe(); // Reset the game

		if (isExit) return 0; // If statement to close the game
	}

	return 0;
}