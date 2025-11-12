#pragma once
#include "Ball.h"
#include "grid.h"
class Cleaner
{
private:
	bool IsCollided(Ball* ballOne, Ball* ballTwo);
	int gridNav[4][2];
	void Shift(Ball* ballOne, Ball* ballTwo);
	void WallCollide(Ball* ball);
public:
	Cleaner();
	~Cleaner();
	void CleanSpace(Grid& grid, int cycles); 
};

