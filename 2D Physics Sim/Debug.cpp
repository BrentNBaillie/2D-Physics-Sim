#pragma once
#include <iostream>
#include "Debug.h" 

using namespace std;

// Print New Lines -------------------------------------------------------------------------------------------------
void Printnl(const string& message){ cout << message << endl; }
void Printnl(int& message){ cout << message << endl; }
void Printnl(float& message){ cout << message << endl; }
void Printnl(double& message){ cout << message << endl; }
void Printnl(const char& message){ cout << message << endl; }

// Print Lines -----------------------------------------------------------------------------------------------------
void Print(const string& message) { cout << message; }
void Print(int& message) { cout << message; }
void Print(float& message) { cout << message; }
void Print(double& message) { cout << message; }
void Print(const char& message) { cout << message; }

// Print 1D Vectors ------------------------------------------------------------------------------------------------
void Print(vector<string>& array1D)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array1D.size(); i++)
	{
		cout << array1D[i] << endl; 
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(vector<int>& array1D)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array1D.size(); i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(vector<float>& array1D)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array1D.size(); i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(vector<double>& array1D)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array1D.size(); i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(vector<char>& array1D)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array1D.size(); i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}

// Print 2D Vectors ------------------------------------------------------------------------------------------------
void Print(vector<vector<string>>& array2D)
{ 
	cout << "2D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array2D.size(); i++)    
	{
		for (int j = 0; j < array2D[i].size(); j++)
		{
			if (j == array2D[i].size() - 1)
			{
				cout << array2D[i][j] << endl;
				break;
			}
			cout << array2D[i][j] << ", ";
		}
		cout << ' ' << endl;
	}
	cout << "2D Array Print End" << endl;
}
void Print(vector<vector<int>>& array2D)
{
	cout << "2D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array2D.size(); i++)
	{
		for (int j = 0; j < array2D[i].size(); j++)
		{
			if (j == array2D[i].size() - 1)
			{
				cout << array2D[i][j] << endl;
				break;
			}
			cout << array2D[i][j] << ", ";
		}
		cout << ' ' << endl;
	}
	cout << "2D Array Print End" << endl;
}
void Print(vector<vector<float>>& array2D)
{
	cout << "2D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array2D.size(); i++)
	{
		for (int j = 0; j < array2D[i].size(); j++)
		{
			if (j == array2D[i].size() - 1)
			{
				cout << array2D[i][j] << endl;
				break;
			}
			cout << array2D[i][j] << ", ";
		}
		cout << ' ' << endl;
	}
	cout << "2D Array Print End" << endl;
}
void Print(vector<vector<double>>& array2D)
{
	cout << "2D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array2D.size(); i++)
	{
		for (int j = 0; j < array2D[i].size(); j++)
		{
			if (j == array2D[i].size() - 1)
			{
				cout << array2D[i][j] << endl;
				break;
			}
			cout << array2D[i][j] << ", ";
		}
		cout << ' ' << endl;
	}
	cout << "2D Array Print End" << endl;
}
void Print(vector<vector<char>>& array2D)
{
	cout << "2D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array2D.size(); i++)
	{
		for (int j = 0; j < array2D[i].size(); j++)
		{
			if (j == array2D[i].size() - 1)
			{
				cout << array2D[i][j] << endl;
				break;
			}
			cout << array2D[i][j] << ", ";
		}
		cout << ' ' << endl;
	}
	cout << "2D Array Print End" << endl;
}

// Print 3D Vectors ------------------------------------------------------------------------------------------------
void Print(vector<vector<vector<string>>>& array3D)
{
	cout << "3D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array3D.size(); i++) 
	{
		for (int j = 0; j < array3D[i].size(); j++)
		{
			cout << '(';
			for (int k = 0; k < array3D[i][j].size(); k++)
			{
				if (k == array3D[i][j].size() - 1)
				{
					cout << array3D[i][j][k] << endl;
					break;
				}
				cout << array3D[i][j][k] << ", "; 
			}
			if (j == array3D[i].size() - 1)
			{
				cout << ")" << endl;
				break;
			}
			cout << ") ";
		}
		cout << ' ' << endl;
	}
	cout << "3D Array Print End" << endl;
}
void Print(vector<vector<vector<int>>>& array3D)
{
	cout << "3D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array3D.size(); i++)
	{
		for (int j = 0; j < array3D[i].size(); j++)
		{
			cout << '(';
			for (int k = 0; k < array3D[i][j].size(); k++)
			{
				if (k == array3D[i][j].size() - 1)
				{
					cout << array3D[i][j][k];
					break;
				}
				cout << array3D[i][j][k] << ", ";
			}
			if (j == array3D[i].size() - 1)
			{
				cout << ")" << endl;
				break;
			}
			cout << ") ";
		}
		cout << ' ' << endl;
	}
	cout << "3D Array Print End" << endl;
}
void Print(vector<vector<vector<float>>>& array3D)
{
	cout << "3D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array3D.size(); i++)
	{
		for (int j = 0; j < array3D[i].size(); j++)
		{
			cout << '(';
			for (int k = 0; k < array3D[i][j].size(); k++)
			{
				if (k == array3D[i][j].size() - 1)
				{
					cout << array3D[i][j][k] << endl;
					break;
				}
				cout << array3D[i][j][k] << ", ";
			}
			if (j == array3D[i].size() - 1)
			{
				cout << ")" << endl;
				break;
			}
			cout << ") ";
		}
		cout << ' ' << endl;
	}
	cout << "3D Array Print End" << endl;
}
void Print(vector<vector<vector<double>>>& array3D)
{
	cout << "3D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array3D.size(); i++)
	{
		for (int j = 0; j < array3D[i].size(); j++)
		{
			cout << '(';
			for (int k = 0; k < array3D[i][j].size(); k++)
			{
				if (k == array3D[i][j].size() - 1)
				{
					cout << array3D[i][j][k] << endl;
					break;
				}
				cout << array3D[i][j][k] << ", ";
			}
			if (j == array3D[i].size() - 1)
			{
				cout << ")" << endl;
				break;
			}
			cout << ") ";
		}
		cout << ' ' << endl;
	}
	cout << "3D Array Print End" << endl;
}
void Print(vector<vector<vector<char>>>& array3D)
{
	cout << "3D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < array3D.size(); i++)
	{
		for (int j = 0; j < array3D[i].size(); j++)
		{
			cout << '(';
			for (int k = 0; k < array3D[i][j].size(); k++)
			{
				if (k == array3D[i][j].size() - 1)
				{
					cout << array3D[i][j][k] << endl;
					break;
				}
				cout << array3D[i][j][k] << ", ";
			}
			if (j == array3D[i].size() - 1)
			{
				cout << ")" << endl;
				break;
			}
			cout << ") ";
		}
		cout << ' ' << endl;
	}
	cout << "3D Array Print End" << endl;
}

// Print 1D Arrays -------------------------------------------------------------------------------------------------
void Print(string array1D[], int size)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(int array1D[], int size)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(float array1D[], int size)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(double array1D[], int size)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}
void Print(char array1D[], int size)
{
	cout << "1D Array Print Start." << endl;
	cout << ' ' << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array1D[i] << endl;
	}
	cout << ' ' << endl;
	cout << "1D Array Print End" << endl;
}