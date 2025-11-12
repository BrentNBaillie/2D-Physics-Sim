#include "Cleaner.h"
#include "Grid.h"

Cleaner::Cleaner() : gridNav{ {1,0},{1,1},{0,1},{-1,1} }
{

}

Cleaner::~Cleaner() {}

bool Cleaner::IsCollided(Ball* ballOne, Ball* ballTwo)
{
	return (ballTwo->position - ballOne->position).SquareSum() <= ballDiameterSquared;
}

void Cleaner::WallCollide(Ball* ball)
{
	if (ball->position.X < ballRadius)
	{
		ball->position.X = ballRadius;
	}
	else if (ball->position.X > screenWidth - ballRadius)
	{
		ball->position.X = screenWidth - ballRadius;
	}
	if (ball->position.Y > screenHeight - ballRadius)
	{
		ball->position.Y = screenHeight - ballRadius;
	}
	else if (ball->position.Y < ballRadius)
	{
		ball->position.Y = ballRadius;
	}
}

void Cleaner::Shift(Ball* ballOne, Ball* ballTwo)
{
	Vect2 delta = ballTwo->position - ballOne->position;
	delta /= 2.0f;
	Vect2 midpoint = ballOne->position + delta;
	delta.Normalize();

	ballTwo->position = midpoint + delta * ballRadius;
	ballOne->position = midpoint - delta * ballRadius;
}

void Cleaner::CleanSpace(Grid& grid, int cycles)
{
	for (int cycle = 0; cycle < cycles; cycle++)
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
								Shift(grid.grid[x][y][i], grid.grid[x][y][j]);
							}
						}
						WallCollide(grid.grid[x][y][i]);
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
									Shift(grid.grid[x][y][i], grid.grid[cell_x][cell_y][j]);
								}
							}
						}
					}
				}
			}
		}
	}
}