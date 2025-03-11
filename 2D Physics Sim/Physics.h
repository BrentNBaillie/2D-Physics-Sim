#pragma once

#include "Grid.h"

using namespace std;

class Physics
{
private:
	float xGravity, yGravity, Vx, Vy, collCoefficient, dragCoefficient, distance, dX, dY, Unit[4], BallOneVel[4], BallTwoVel[4], scale, distSqared;
	bool oneIsFacing, twoIsFacing;
	int gridNav[4][2];
	int loopStart, loopEnd;
	void UnitVectors();
	void VelocityVectors(Ball& ball, float(&BallVel)[4]);
	void CalculateBallCollide(Ball& ballOne, Ball& ballTwo);
public:
	Physics();
	~Physics();
	void BallCollide(Grid& grid, vector<Ball>& balls);
	void UpdatePosition(Ball& ball, float dt);
	void WallCollide(Ball& ball);
};