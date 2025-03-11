#pragma once
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

Grid::Grid() : grid(gridSize, vector<vector<int>>(gridSize, vector<int>(0))), countID(gridSize, vector<int>(gridSize, 0)), ranges(2, vector<float>(gridSize, 0))
{
	InitializeRanges();
}

Grid::~Grid() {}

void Grid::InitializeRanges()
{
	for (int i = 0; i < gridSize; i++)
	{
		ranges[0][i] = (screenWidth / static_cast<float>(gridSize)) * (i + 1);
		ranges[1][i] = (screenHeight / static_cast<float>(gridSize)) * (i + 1); 
	}
}

void Grid::ClearGrid()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			grid[i][j].clear();
			countID[i][j] = 0; 
		}
	}
}

void Grid::UpdateGrid(vector<Ball>& balls) 
{
	ClearGrid(); 
	for (Ball& ball : balls)
	{
		for (int i = 0; i < gridSize; i++)
		{
			if (ball.x < ranges[0][i])
			{
				for (int j = 0; j < gridSize; j++)
				{
					if (ball.y < ranges[1][j])
					{
						grid[i][j].emplace_back(ball.id);
						countID[i][j]++;
						break;
					}
				}
				break;
			}
		}
	}
}