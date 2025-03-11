#pragma once
#include <SFML/Graphics.hpp>

#include "Globals.h" 
#include "Physics.h"
#include "Ball.h"
#include "DeltaTime.h"
#include "Grid.h"
#include "Debug.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <random>
#include <thread>

using namespace std::chrono;
using namespace std;

void DrawBallFrame(sf::RenderWindow& window, vector<Ball>& balls);
void CalculateBallFrame(Physics& physics, DeltaTime& deltaTime, vector<Ball>& balls, Grid& grid);

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "2D Ball Simulation");

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> rand(0.0, 1.0);

    Physics physics;
    vector<Ball> frameOne;
    vector<Ball> frameTwo;
    DeltaTime deltaTime;
    Grid grid;

    for(int i = 0; i < ballCount; i++)
    {
        frameOne.emplace_back(screenWidth * rand(gen), screenHeight * rand(gen), 100 * rand(gen), 100 * rand(gen), i);
    }

    frameTwo = frameOne; 

    vector<vector<Ball>> frame = {frameOne, frameTwo};
    
    while (window.isOpen())
    {
        auto start = high_resolution_clock::now();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       
        grid.UpdateGrid(frame[1]);
        CalculateBallFrame(physics, deltaTime, frame[1], grid);
        frame[0] = frame[1];
        DrawBallFrame(window, frame[0]);
        
        window.display();
        auto end = high_resolution_clock::now();
        deltaTime.NewTime(static_cast<float>(duration_cast<microseconds>(end - start).count()) / 1000000.0f);
        //this_thread::sleep_for(chrono::seconds(2));
    }

    return 0;
}

void DrawBallFrame(sf::RenderWindow& window, vector<Ball>& balls)
{
    for (Ball& ball : balls)
    {
        ball.DrawBall(window);
    }
}

void CalculateBallFrame(Physics& physics, DeltaTime& deltaTime, vector<Ball>& balls, Grid& grid)
{
    for (Ball& ball : balls)
    {
        physics.WallCollide(ball);
        physics.BallCollide(grid, balls);
        physics.UpdatePosition(ball, deltaTime.dT);
    }
}