#include <iostream>
#include "raylib.h"
#include "Simulation.hpp"

int main(void)
{
    Color GREY = {169, 169, 169, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation sim(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    while(WindowShouldClose() == false)
    {
        sim.Update();

        BeginDrawing();
        ClearBackground(GREY);
        sim.Draw();
        EndDrawing();
    }
    CloseWindow();
}
