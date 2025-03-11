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
	vector<vector<vector<int>>> grid;
	vector<vector<int>> countID;
	Grid();
	~Grid();
	void UpdateGrid(vector<Ball>& balls);
};