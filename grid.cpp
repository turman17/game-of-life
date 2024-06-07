#include "Grid.hpp"


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

void Grid::SetValue(int row, int col, int value)
{
    if(IsInBounds(row, col))
        _cells[row][col] = value;
}

int Grid::GetValue(int row, int col)
{
    if(IsInBounds(row, col))
        return _cells[row][col];
    return 0;
}

bool Grid::IsInBounds(int row, int col)
{
    return row >= 0 && row < _rows && col >= 0 && col < _colomns;
}

void Grid::FillRandom()
{
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _colomns; j++)
        {
            int randomValue = GetRandomValue(0, 4);
            _cells[i][j] = (randomValue == 4) ? 1 : 0;
        }
    }
}
