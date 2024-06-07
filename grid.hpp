#pragma once
#include "raylib.h"
#include <vector>

class Grid
{
public:
    Grid(int width, int height, int cellSize)
        : _rows(height / cellSize), _colomns(width / cellSize), _cellSize(cellSize), _cells(_rows, std::vector<int>(_colomns, 0)) {}
    void draw();
    void SetValue(int row, int col, int value);
    int GetValue(int row, int col);
    bool IsInBounds(int row, int col);
    int GetRows() { return _rows; }
    int GetColomns() { return _colomns; }
    void FillRandom();
private:
    int _rows;
    int _colomns;
    int _cellSize;
    std::vector<std::vector<int>> _cells;
};
