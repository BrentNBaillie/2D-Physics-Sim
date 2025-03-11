#pragma once

#include "vector"

using namespace std;

void Printnl(const string& message);
void Printnl(int& message);
void Printnl(float& message);
void Printnl(double& message);
void Printnl(const char& message);

void Print(const string& message);
void Print(int& message);
void Print(float& message);
void Print(double& message);
void Print(const char& message);

void Print(vector<string>& array1D);
void Print(vector<int>& array1D);
void Print(vector<float>& array1D);
void Print(vector<double>& array1D);
void Print(vector<char>& array1D);
 
void Print(vector<vector<string>>& array2D);
void Print(vector<vector<int>>& array2D);
void Print(vector<vector<float>>& array2D);
void Print(vector<vector<double>>& array2D);
void Print(vector<vector<char>>& array2D);

void Print(vector<vector<vector<string>>>& array3D);
void Print(vector<vector<vector<int>>>& array3D);
void Print(vector<vector<vector<float>>>& array3D);
void Print(vector<vector<vector<double>>>& array3D);
void Print(vector<vector<vector<char>>>& array3D);

void Print(string array1D[], int size);
void Print(int array1D[], int size);
void Print(float array1D[], int size);
void Print(double array1D[], int size);
void Print(char array1D[], int size); 