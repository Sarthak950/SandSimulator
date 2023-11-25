#include <cstdio>
#include <iostream>
#include <raylib.h>
#include <bits/stdc++.h>

int screenWidth = 800;
int screenHeight = 800;

const int gridSize = 200;
// int cellSize = screenWidth / gridSize;
int cellSize = 4;

// create the grid as a 2d static array 
int grid[gridSize][gridSize];

/*
//we are making a sand simulator so there are 4 states of a cell
    1 Empty 
    2 Rock which are immovable 
    3 Sand which falls down 
    4 Water which flows down and to the sides
*/

#define EMPTY 0
#define ROCK 1
#define SAND 2
#define WATER 3


// set a stage of 3 blocks of rock a little above the ground 
void InitializeGrid() {

    // Border aroound the grid 
    for (int i = 0; i < gridSize; i++) {
        grid[gridSize - 1][i] = ROCK;
        grid[i][gridSize - 1] = ROCK;
        grid[0][i] = ROCK;
        grid[i][0] = ROCK;
    }

    // set some sand in the air 
    for (int i = 0; i < 30; i++) {
        grid[gridSize - 100][i + 50] = SAND;
    }
    
}

void UpdateGrid() {

    for ( int i = gridSize -1 ; i > 0 ; i-- ) {
        for ( int j = 0 ; j < gridSize ; j++ ) {
            if (grid[i][j] == SAND) {
                if (grid[i + 1][j] == EMPTY) {
                    grid[i + 1][j] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i + 1][j - 1] == EMPTY) {
                    grid[i + 1][j - 1] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i + 1][j + 1] == EMPTY) {
                    grid[i + 1][j + 1] = SAND;
                    grid[i][j] = EMPTY;
                }
            }
            else if (grid[i][j] == WATER) {
                if (grid[i + 1][j] == EMPTY) {
                    grid[i + 1][j] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i + 1][j - 1] == EMPTY) {
                    grid[i + 1][j - 1] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i + 1][j + 1] == EMPTY) {
                    grid[i + 1][j + 1] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i][j - 1] == EMPTY) {
                    grid[i][j - 1] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i][j + 1] == EMPTY) {
                    grid[i][j + 1] = WATER;
                    grid[i][j] = EMPTY;
                }
            }
        }
    }

}




void DrawBox (int x, int y, int width, int height, int state) {

    if (state == ROCK) {
        DrawRectangle(x, y, width, height, GRAY);
    }
    else if (state == SAND) {
        DrawRectangle(x, y, width, height, YELLOW);
    }
    else if (state == WATER) {
        DrawRectangle(x, y, width, height, BLUE);
    }

}


int main() {




    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    InitializeGrid();



    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update the grid
        UpdateGrid();

        // Render the grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j]) {
                    DrawBox (i * cellSize, j * cellSize, cellSize, cellSize, grid[i][j]);
                    // DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, BLACK);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

