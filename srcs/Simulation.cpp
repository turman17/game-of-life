#include "Simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.draw();
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveneighbours(int row, int col)
{
    int count = 0;
    std::vector<std::pair<int, int>> neighbours = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}};

    for (const auto &neighbour : neighbours)
    {
        int r = (row + neighbour.first + grid.GetRows()) % grid.GetRows();
        int c = (col + neighbour.second + grid.GetColomns()) % grid.GetColomns();

        if (grid.IsInBounds(r, c) && grid.GetValue(r, c) == 1)
        {
            count++;
        }
    }
    return count;
}

void Simulation::Update()
{
    for(int i = 0; i < grid.GetRows(); i++)
    {
        for(int j = 0; j < grid.GetColomns(); j++)
        {
            int liveNeighbours = CountLiveneighbours(i, j);

            if(grid.GetValue(i, j) == 1)
            {
                if(liveNeighbours < 2 || liveNeighbours > 3)
                    nextGrid.SetValue(i, j, 0);
                else
                    nextGrid.SetValue(i, j, 1);
            }
            else
            {
                if(liveNeighbours == 3)
                    nextGrid.SetValue(i, j, 1);
                else
                    nextGrid.SetValue(i, j, 0);
            }
        }
    }
    grid = nextGrid;
}