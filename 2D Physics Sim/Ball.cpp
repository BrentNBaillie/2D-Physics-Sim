#include <iostream>
#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Ball.h"
#include "Vect2.h"

#include <cmath>

Ball::Ball(Vect2 newPosition, Vect2 newVelocity , int id) 
	: position(newPosition.X,newPosition.Y), velocity(newVelocity.X,newVelocity.Y), id(id), speed(0), speedSquared(0)
{
	circle.setRadius(ballRadius);
	circle.setOrigin(ballRadius, ballRadius);
	circle.setPosition(position.X, screenHeight - position.Y);
	BallVelocitymath();
	UpdateColor();
}

Ball::~Ball(){}

void Ball::DrawBall(sf::RenderWindow& window)
{
	circle.setPosition(position.X, screenHeight - position.Y);
	BallVelocitymath();
	UpdateColor();
	window.draw(circle);
}

void Ball::BallVelocitymath()
{
	speedSquared = velocity.SquareSum();
	speed = sqrt(speedSquared);
}

void Ball::UpdateColor()
{
	
	if (speed <= 100)
	{
		color.b = std::max(0.0f, (float)(-0.102 * pow(speed, 2) + 255));
		color.g = std::max(0.0f, (float)(-0.102 * pow(speed, 2) + 10.2 * speed));
		color.r = std::max(0.0f, (float)(-0.102 * pow(speed, 2) + 20.4 * speed - 765));
	}
	else
	{
		color.b = 0;
		color.g = 0;
		color.r = 255;
	}
	circle.setFillColor(color);
}