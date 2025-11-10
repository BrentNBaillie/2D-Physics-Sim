#pragma once

#include "Grid.h"
#include "DeltaTime.h"

using namespace std;

class Physics
{
private:
	float collCoefficient, dragCoefficient, Unit[4], BallOneVel[4], BallTwoVel[4], scale, distSquared, distance;
	Vect2 velocity, gravity, delta;
	bool oneIsFacing, twoIsFacing;
	int loopStart, loopEnd, gridNav[4][2];
	void SetUnitVectors();
	void SetVelocityVectors(Ball* ball, float(&BallVel)[4]);
	bool IsCollided(Ball* ballOne, Ball* ballTwo);
	void CalculateBallCollide(Ball* ballOne, Ball* ballTwo);
	void BallCollide(Grid& grid);
	void UpdatePosition(Ball& ball, float dt);
	void WallCollide(Ball& ball);
public:
	Physics();
	~Physics();
	void SimulateFrame(std::vector<Ball>& balls, Grid& grid, DeltaTime& deltaTime);
};