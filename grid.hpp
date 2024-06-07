#pragma once
#include "raylib.h"
#include <vector>

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : _rows(height / cellSize), _colomns(width / cellSize), _cellSize(cellSize), _cells(_rows, std::vector<int>(_colomns, 0)) {}
    void draw();

private:
    int _rows;
    int _colomns;
    int _cellSize;
    std::vector<std::vector<int>> _cells;
};
