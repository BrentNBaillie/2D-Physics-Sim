#include "Grid.h"
#include "Globals.h"
#include "Debug.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

Grid::Grid() : gridWidth((int)(screenWidth / (6 * ballDiameter))), gridHeight((int)(screenHeight / (6 * ballDiameter))), 
grid(gridWidth, vector<vector<Ball*>>(gridHeight, vector<Ball*>(0))), ranges(2)
{
	ranges[0].resize(gridWidth, 0.0f);
	ranges[1].resize(gridHeight, 0.0f);
	InitializeRanges();
}

Grid::~Grid() {}

void Grid::InitializeRanges()
{
	for (int x = 0; x < gridWidth; x++)
	{
		ranges[0][x] = (screenWidth / static_cast<float>(gridWidth)) * (x + 1);
	}
	for (int y = 0; y < gridHeight; y++)
	{
		ranges[1][y] = (screenHeight / static_cast<float>(gridHeight)) * (y + 1);
	}
}

void Grid::ClearGrid()
{
	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			grid[x][y].clear();
		}
	}
}

void Grid::UpdateGrid(vector<Ball>& balls) 
{
	ClearGrid(); 
	for (Ball& ball : balls)
	{
		for (int x = 0; x < gridWidth; x++)
		{
			if (ball.position.X < ranges[0][x])
			{
				for (int y = 0; y < gridHeight; y++)
				{
					if (ball.position.Y < ranges[1][y])
					{
						grid[x][y].emplace_back(&ball);
						break;
					}
				}
				break;
			}
		}
	}
}