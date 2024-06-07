#include "grid.hpp"

void Grid::draw()
{
    for (int row = 0; row < _rows; row++)
    {
        for (int col = 0; col < _colomns; col++)
        {
            Color color = _cells[row][col] ? (Color){0, 255, 0, 255} : (Color){55, 55, 55, 255};
            DrawRectangle(col * _cellSize, row * _cellSize, _cellSize - 1, _cellSize - 1, color);
        }
    }
}
