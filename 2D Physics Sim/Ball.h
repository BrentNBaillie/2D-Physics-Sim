#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	float velocity, vSquared;
	sf::CircleShape circle;
	sf::Color color;
	void UpdateColor();
	void BallVelocitymath();
public:
	float x, y, Vx, Vy;
	int id;
	Ball(float x, float y, float Vx, float Vy, int id);
	~Ball();
	void DrawBall(sf::RenderWindow& window);
};