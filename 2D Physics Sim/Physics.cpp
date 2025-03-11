#pragma once
#include <iostream>
#include <cmath>
#include "Physics.h"
#include "Ball.h"
#include "Grid.h"
#include "Globals.h" 
#include "Debug.h"

using namespace std;

enum NormalTangent {Xn, Yn, Xt, Yt};

Physics::Physics()
	: xGravity(0), yGravity(-10.0f), Vx(0), Vy(0), collCoefficient(0.99), dragCoefficient(0), distance(0), dX(0), dY(0), 
	Unit{ 0,0,0,0 }, BallOneVel{ 0,0,0,0 }, BallTwoVel{ 0,0,0,0 }, oneIsFacing(false), twoIsFacing(false), scale(4), distSqared(0), 
	gridNav{ {1,0},{1,1},{0,1},{-1,1} }, loopStart(0), loopEnd(0)
{}

Physics::~Physics(){}

void Physics::UpdatePosition(Ball& ball, float dt)
{
	Vx = (xGravity - ball.Vx * dragCoefficient) * dt;
	Vy = (yGravity - ball.Vy * dragCoefficient) * dt;
	ball.Vx += Vx * scale;
	ball.Vy += Vy * scale; 
	ball.x += (ball.Vx + 0.5 * Vx) * dt * scale; 
	ball.y += (ball.Vy + 0.5 * Vy) * dt * scale; 
}

void Physics::WallCollide(Ball& ball)
{
	if (ball.x < ballRadius)
	{
		ball.Vx *= -collCoefficient;
		ball.x = ballRadius;
	}
	else if (ball.x > screenWidth - ballRadius)
	{
		ball.Vx *= -collCoefficient;
		ball.x = screenWidth - ballRadius;
	}
	if (ball.y > screenHeight - ballRadius)
	{
		ball.Vy *= -collCoefficient;
		ball.y = screenHeight - ballRadius;
	}
	else if (ball.y < ballRadius)
	{
		ball.Vy *= -collCoefficient;
		ball.y = ballRadius;
	}
}

void Physics::UnitVectors()
{
	Unit[Xn] = dX / distance;
	Unit[Yn] = dY / distance;
	Unit[Xt] = Unit[Yn];
	Unit[Yt] = -Unit[Xn];
}

void Physics::VelocityVectors(Ball& ball, float(&BallVel)[4])
{
	BallVel[Xn] = Unit[Xn] * (ball.Vx * Unit[Xn] + ball.Vy * Unit[Yn]);
	BallVel[Yn] = Unit[Yn] * (ball.Vx * Unit[Xn] + ball.Vy * Unit[Yn]);
	BallVel[Xt] = Unit[Xt] * (ball.Vx * Unit[Xt] + ball.Vy * Unit[Yt]);
	BallVel[Yt] = Unit[Yt] * (ball.Vx * Unit[Xt] + ball.Vy * Unit[Yt]);
}

void Physics::BallCollide(Grid& grid, vector<Ball>& balls) 
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (grid.countID[i][j] == 0)
			{
				continue;
			}
			for (int k = 0; k < grid.countID[i][j]; k++)
			{
				for (int l = k + 1; l < grid.countID[i][j]; l++)
				{
					dX = balls[l].x - balls[k].x;
					dY = balls[l].y - balls[k].y;
					distSqared = dX * dX + dY * dY;

					if (distSqared <= ballDiameterSquared)
					{
						distance = sqrt(distSqared);
						CalculateBallCollide(balls[k], balls[l]);
					}
				}

				if (j == gridSize - 1)
				{
					loopStart = 0;
					loopEnd = 0;
				}
				else if (i == 0)
				{
					loopStart = 0;
					loopEnd = 2;
				}
				else if (i == gridSize - 1)
				{
					loopStart = 2;
					loopEnd = 3;
				}

				if (i != gridSize - 1 && j != gridSize - 1)
				{
					for (int l = loopStart; l <= loopEnd; l++)
					{
						//Out of bounds error
						if (grid.countID[i + gridNav[l][0]][j + gridNav[l][1]] == 0)
						{
							continue;
						}

						//Out of bounds error
						for (int m = 0; m < grid.countID[i + gridNav[l][0]][j + gridNav[l][1]]; m++)
						{
							dX = balls[m].x - balls[k].x;
							dY = balls[m].y - balls[k].y;
							distSqared = dX * dX + dY * dY;

							if (distSqared <= ballDiameterSquared)
							{
								distance = sqrt(distSqared);
								CalculateBallCollide(balls[k], balls[m]);
							}
						}
					}
				}
			}
		}
	}
}

void Physics::CalculateBallCollide(Ball& ballOne, Ball& ballTwo)
{
	UnitVectors();
	VelocityVectors(ballOne, BallOneVel);
	VelocityVectors(ballTwo, BallTwoVel);

	oneIsFacing = BallOneVel[Xn] * dX + BallOneVel[Yn] * dY > 0;
	twoIsFacing = BallTwoVel[Xn] * dX + BallTwoVel[Yn] * dY < 0;

	if ((oneIsFacing && twoIsFacing) ||
		(oneIsFacing && (BallOneVel[Xn] > BallTwoVel[Xn] || BallOneVel[Yn] > BallTwoVel[Yn])) ||
		(twoIsFacing && (BallTwoVel[Xn] > BallOneVel[Xn] || BallTwoVel[Yn] > BallOneVel[Yn])))
	{
		ballOne.Vx = (collCoefficient * BallTwoVel[Xn]) + BallOneVel[Xt];
		ballOne.Vy = (collCoefficient * BallTwoVel[Yn]) + BallOneVel[Yt];
		ballTwo.Vx = (collCoefficient * BallOneVel[Xn]) + BallTwoVel[Xt];
		ballTwo.Vy = (collCoefficient * BallOneVel[Yn]) + BallTwoVel[Yt];
	}
}

