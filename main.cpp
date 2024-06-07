#include <iostream>
#include "raylib.h"
#include "grid.hpp"

int main(void)
{
    Color GREY = {169, 169, 169, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(GREY);
        grid.draw();
        EndDrawing();
    }
    CloseWindow();
}
