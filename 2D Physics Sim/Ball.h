#pragma once
#include <SFML/Graphics.hpp>
#include "Vect2.h"

class Ball
{
private:
	float speedSquared;
	sf::CircleShape circle;
	sf::Color color;
	void UpdateColor();
	void BallVelocitymath();
public:
	Vect2 position, velocity;
	float speed;
	int id;
	Ball(Vect2 newPosition, Vect2 newVelocity, int id);
	~Ball();
	void DrawBall(sf::RenderWindow& window);
};