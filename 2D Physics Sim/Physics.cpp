#include <iostream>
#include <cmath>
#include "Physics.h"
#include "Ball.h"
#include "Grid.h"
#include "Globals.h" 
#include "Debug.h"
#include "Vect2.h"

enum NormalTangent {Xn, Yn, Xt, Yt};

Physics::Physics()
	: gravity(0,-10.0f), velocity(0,0), collCoefficient(0.9f), dragCoefficient(0), delta(0,0),
	Unit{ 0,0,0,0 }, BallOneVel{ 0,0,0,0 }, BallTwoVel{ 0,0,0,0 }, oneIsFacing(false), twoIsFacing(false), scale(10), distSquared(0), 
	gridNav{ {1,0},{1,1},{0,1},{-1,1} }, loopStart(0), loopEnd(0), distance(0)
{}

Physics::~Physics(){}

void Physics::UpdatePosition(Ball& ball, float dt)
{
	velocity.X = (gravity.X - ball.velocity.X * dragCoefficient) * dt;
	velocity.Y = (gravity.Y - ball.velocity.Y * dragCoefficient) * dt;
	ball.velocity.X += velocity.X * scale;
	ball.velocity.Y += velocity.Y * scale; 
	ball.position.X += (ball.velocity.X + 0.5 * velocity.X) * dt * scale; 
	ball.position.Y += (ball.velocity.Y + 0.5 * velocity.Y) * dt * scale; 
}

void Physics::WallCollide(Ball& ball)
{
	if (ball.position.X < ballRadius)
	{
		ball.velocity.X *= -collCoefficient;
		ball.position.X = ballRadius;
	}
	else if (ball.position.X > screenWidth - ballRadius)
	{
		ball.velocity.X *= -collCoefficient;
		ball.position.X = screenWidth - ballRadius;
	}
	if (ball.position.Y > screenHeight - ballRadius)
	{
		ball.velocity.Y *= -collCoefficient;
		ball.position.Y = screenHeight - ballRadius;
	}
	else if (ball.position.Y < ballRadius)
	{
		ball.velocity.Y *= -collCoefficient;
		ball.position.Y = ballRadius;
	}
}

void Physics::SetUnitVectors()
{
	delta.Normalize();
	Unit[Xn] = delta.X;
	Unit[Yn] = delta.Y;
	Unit[Xt] = Unit[Yn];
	Unit[Yt] = -Unit[Xn];
}

void Physics::SetVelocityVectors(Ball* ball, float(&BallVel)[4])
{
	BallVel[Xn] = Unit[Xn] * (ball->velocity.X * Unit[Xn] + ball->velocity.Y * Unit[Yn]);
	BallVel[Yn] = Unit[Yn] * (ball->velocity.X * Unit[Xn] + ball->velocity.Y * Unit[Yn]);
	BallVel[Xt] = Unit[Xt] * (ball->velocity.X * Unit[Xt] + ball->velocity.Y * Unit[Yt]);
	BallVel[Yt] = Unit[Yt] * (ball->velocity.X * Unit[Xt] + ball->velocity.Y * Unit[Yt]);
}

bool Physics::IsCollided(Ball* ballOne, Ball* ballTwo)
{
	delta = ballTwo->position - ballOne->position;
	distSquared = delta.SquareSum();

	return distSquared <= ballDiameterSquared;
}

void Physics::CalculateBallCollide(Ball* ballOne, Ball* ballTwo)
{
	SetUnitVectors();
	SetVelocityVectors(ballOne, BallOneVel);
	SetVelocityVectors(ballTwo, BallTwoVel);

	oneIsFacing = BallOneVel[Xn] * delta.X + BallOneVel[Yn] * delta.Y > 0;
	twoIsFacing = BallTwoVel[Xn] * delta.X + BallTwoVel[Yn] * delta.Y < 0;

	if ((oneIsFacing && twoIsFacing) ||
		(oneIsFacing && (BallOneVel[Xn] > BallTwoVel[Xn] || BallOneVel[Yn] > BallTwoVel[Yn])) ||
		(twoIsFacing && (BallTwoVel[Xn] > BallOneVel[Xn] || BallTwoVel[Yn] > BallOneVel[Yn])))
	{
		ballOne->velocity.X = (collCoefficient * BallTwoVel[Xn]) + BallOneVel[Xt];
		ballOne->velocity.Y = (collCoefficient * BallTwoVel[Yn]) + BallOneVel[Yt];
		ballTwo->velocity.X = (collCoefficient * BallOneVel[Xn]) + BallTwoVel[Xt];
		ballTwo->velocity.Y = (collCoefficient * BallOneVel[Yn]) + BallTwoVel[Yt];
	}
}

void Physics::Shift(Ball* ballOne, Ball* ballTwo)
{
	Vect2 delta = ballTwo->position - ballOne->position;
	delta /= 2.0f;
	Vect2 midpoint = ballOne->position + delta;
	delta.Normalize();

	ballTwo->position = midpoint + delta * ballRadius;
	ballOne->position = midpoint - delta * ballRadius;
}

void Physics::BallCollide(Grid& grid)
{
	for (int x = 0; x < grid.gridWidth; x++)
	{
		for (int y = 0; y < grid.gridHeight; y++)
		{
			if (grid.grid[x][y].size() == 0)
			{
				continue;
			}
			else
			{
				for (int i = 0; i < grid.grid[x][y].size(); i++)
				{
					for (int j = i + 1; j < grid.grid[x][y].size(); j++)
					{
						if (IsCollided(grid.grid[x][y][i], grid.grid[x][y][j]))
						{
							CalculateBallCollide(grid.grid[x][y][i], grid.grid[x][y][j]);
							Shift(grid.grid[x][y][i], grid.grid[x][y][j]);
						}
					}
					for (int cell = 0; cell < 4; cell++)
					{
						int cell_x = x + gridNav[cell][0];
						int cell_y = y + gridNav[cell][1];

						if (cell_x == grid.gridWidth || cell_x < 0 || cell_y == grid.gridHeight || cell_y < 0 || !grid.grid[cell_x][cell_y].size())
						{
							continue;
						}

						for (int j = 0; j < grid.grid[cell_x][cell_y].size(); j++)
						{
							if (IsCollided(grid.grid[x][y][i], grid.grid[cell_x][cell_y][j]))
							{
								CalculateBallCollide(grid.grid[x][y][i], grid.grid[cell_x][cell_y][j]);
								Shift(grid.grid[x][y][i], grid.grid[cell_x][cell_y][j]);
							}
						}
					}
				}
			}
		}
	}
}

void Physics::SimulateFrame(std::vector<Ball>& balls, Grid& grid, DeltaTime& deltaTime)
{
	grid.UpdateGrid(balls);

	for (Ball& ball : balls)
	{
		WallCollide(ball);
		BallCollide(grid);
		UpdatePosition(ball, deltaTime.dT);
	}
}