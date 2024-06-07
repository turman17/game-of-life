#pragma once

#include "Grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), nextGrid(width, height, cellSize){
            grid.FillRandom();
        };
    void Draw();
    void SetCellValue(int row, int col, int value);
    int CountLiveneighbours(int row, int col);
    void Update();

private:
    Grid grid;
    Grid nextGrid;
};
