#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Ball.h"

#include <cmath>
#include <algorithm>

Ball::Ball(float x, float y, float Vx, float Vy, int id) : x(x), y(y), Vx(Vx), Vy(Vy), id(id), velocity(0), vSquared(0)
{
	circle.setRadius(ballRadius);
	circle.setOrigin(ballRadius, ballRadius);
	circle.setPosition(x, screenHeight - y);
	BallVelocitymath();
	UpdateColor();
}

Ball::~Ball(){}

void Ball::DrawBall(sf::RenderWindow& window)
{
	circle.setPosition(x, screenHeight - y);
	BallVelocitymath();
	UpdateColor();
	window.draw(circle);
}

void Ball::BallVelocitymath()
{
	vSquared = Vx * Vx + Vy * Vy;
	velocity = sqrt(vSquared);
}

void Ball::UpdateColor()
{
	
	if (velocity <= 100)
	{
		color.b = std::max(0.0f, (float)(-0.102 * vSquared + 255));
		color.g = std::max(0.0f, (float)(-0.102 * vSquared + 10.2 * velocity));
		color.r = std::max(0.0f, (float)(-0.102 * vSquared + 20.4 * velocity - 765));
	}
	else
	{
		color.b = 0;
		color.g = 0;
		color.r = 255;
	}
	circle.setFillColor(color);
}