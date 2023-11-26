#include <cstdio>
#include <iostream>
#include <raylib.h>
#include <bits/stdc++.h>

// Constsants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int GRID_SIZE = 200;
const int CELL_SIZE = 4;
const int FPS = 7;
// not const 
int grid[GRID_SIZE][GRID_SIZE];

/*
    we are making a sand simulator so there are 4 states of a cell
        1. Empty 
        2. Rock which are immovable 
        3. Sand which falls down 
        4. Water which flows down and to the sides
*/

#define EMPTY 0
#define ROCK 1
#define SAND 2
#define WATER 3


// set a stage of 3 blocks of rock a little above the ground 
void InitializeGrid() {

    // Border aroound the grid 
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[GRID_SIZE - 1][i] = ROCK;
        grid[i][GRID_SIZE - 1] = ROCK;
        grid[0][i] = ROCK;
        grid[i][0] = ROCK;
    }

    // set a sand in the center 
    // grid[GRID_SIZE / 2][GRID_SIZE / 2] = SAND;

    // set some sand in the air 
    for (int i = 0; i < 40; i++) {
        grid[GRID_SIZE - 100][(i + 5)*3] = SAND;
    }

}

void UpdateGrid() {
    
    // from bottom left to the top right
    for (int i= 0;i<GRID_SIZE;i++) {
        for ( int j = GRID_SIZE;j>0;j--) {
            if ( grid[i][j] == SAND) {
                if (grid[i][j+1] == EMPTY) {
                    grid[i][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i+1][j+1] == EMPTY) {
                    grid[i+1][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i-1][j+1] == EMPTY) {
                    grid[i-1][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
            }
        }
    }


}




void DrawBox (int x, int y, int width, int height, int state) {

    if (state == EMPTY) {
        // DrawRectangle(x, y, width, height, WHITE);
        DrawRectangle(x, y, width, height, LIME);
    }
    else if (state == ROCK) {
        DrawRectangle(x, y, width, height,  BLACK);
    }
    else if (state == SAND) {
        // DrawRectangle(x, y, width, height, YELLOW);
        DrawRectangle(x, y, width, height, GOLD);
    }
    else if (state == WATER) {
        DrawRectangle(x, y, width, height, BLUE);
    }

}


int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Conway's Game of Life");
    InitializeGrid();
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {

        // Setup the canvas
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Render the grid
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                // if (grid[i][j])
                    DrawBox (i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE, grid[i][j]);


        // Update the grid
        UpdateGrid();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

