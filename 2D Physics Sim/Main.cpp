#pragma once
#include <SFML/Graphics.hpp>

#include "Globals.h" 
#include "Physics.h"
#include "Ball.h"
#include "DeltaTime.h"
#include "Grid.h"
#include "Debug.h"
#include "Cleaner.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <random>
#include <thread>
#include <atomic>
#include <mutex>

void DrawFrame(sf::RenderWindow& window, vector<Ball>& balls);
void CalculateFrame(Physics& physics, vector<Ball>& balls, Grid& grid);
void SpaceBalls(Grid& grid);
std::mutex g_mutex;
std::atomic_bool isReading{ false };
std::atomic_bool isSimulating{ true };

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "2D Ball Simulation");

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> rand(0.0, 1.0);

    Physics physics;
    vector<Ball> frameOne;
    vector<Ball> frameTwo;
    Grid grid;
   

    for(int i = 0; i < ballCount; i++)
    {
        frameOne.emplace_back(Vect2(screenWidth * rand(gen), screenHeight * rand(gen)), Vect2(100 * rand(gen), 100 * rand(gen)), i);
    }

    frameTwo = frameOne; 

    vector<vector<Ball>> frame = {frameOne, frameTwo};

    std::thread physicsThread(CalculateFrame, std::ref(physics), std::ref(frame[1]), std::ref(grid));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        {
            while (isSimulating.load()) {}
            isReading.store(true);
            std::lock_guard<std::mutex> lock(g_mutex);
            frame[0] = frame[1];
            isReading.store(false);
        }
       
        window.clear();
        DrawFrame(window, frame[0]);
        window.display();
    }
    physicsThread.join();

    return 0;
}

void DrawFrame(sf::RenderWindow& window, vector<Ball>& balls)
{
    for (Ball& ball : balls)
    {
        ball.DrawBall(window);
    }
}

void CalculateFrame(Physics& physics, std::vector<Ball>& balls, Grid& grid)
{
    DeltaTime deltaTime;
    Cleaner cleaner;

    while (true)
    {
        while(isReading.load()){}
        isSimulating.store(true);
        auto start = std::chrono::high_resolution_clock::now();
        physics.SimulateFrame(balls, grid, deltaTime);
        auto end = std::chrono::high_resolution_clock::now();
        deltaTime.NewTime(static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 1000000.0f);
        cleaner.CleanSpace(grid, 8);
        isSimulating.store(false);
    }
}