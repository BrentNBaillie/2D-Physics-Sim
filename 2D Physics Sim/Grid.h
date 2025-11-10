#pragma once
#include <vector>
#include "Globals.h"
#include "Ball.h"

using namespace std;

class Grid
{
private:
	vector<vector<float>> ranges;
	void InitializeRanges();
	void ClearGrid();
public:
	int gridWidth, gridHeight;
	vector<vector<vector<Ball*>>> grid;
	Grid();
	~Grid();
	void UpdateGrid(vector<Ball>& balls);
};