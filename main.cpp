/*
 * Author:  Sarthak Sharma [Sarthak950]
 *
    Making a sand simulator so there are 4 states of a cell
        1. Empty 
        2. Rock which are immovable 
        3. Sand which falls down 
        4. Water which flows down and to the sides
*/
#include "raylib.h"
#include <bits/stdc++.h>
#include <string>

// Constsants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int GRID_SIZE = 200;
const int CELL_SIZE = 4;
const int FPS = 60;

// not const 
int grid[GRID_SIZE][GRID_SIZE];
int rockCount = 0;
int sandCount = 0;
int waterCount = 0;

#define EMPTY 0
#define ROCK 1
#define SAND 2
#define WATER 3


// set a stage of 3 blocks of rock a little above the ground 
void InitializeGrid() {

    // Set all cells to Empty
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = EMPTY;

    // Border aroound the grid 
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[GRID_SIZE - 1][i] = ROCK;
        grid[i][GRID_SIZE - 1] = ROCK;
        grid[0][i] = ROCK;
        grid[i][0] = ROCK;
    }

 

}

void KeyPressHandeler () {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    // mouse position needed to be divided by the cell size to get the grid position
    mouseX = mouseX / CELL_SIZE;
    mouseY = mouseY / CELL_SIZE;



    if (IsKeyDown(KEY_SPACE) ) {
        grid[mouseX][mouseY] = ROCK;
    }
    else if (IsKeyDown(KEY_S) ) {
        if (grid[mouseX][mouseY] == EMPTY)   grid[mouseX][mouseY] = SAND;
    }
    else if (IsKeyDown(KEY_W) ) {
        if (grid[mouseX][mouseY] == EMPTY)   grid[mouseX][mouseY] = WATER;
    }
    else if (IsKeyDown(KEY_E) ) {
        if (grid[mouseX][mouseY] == EMPTY)   grid[mouseX][mouseY] = EMPTY;
    }
    else if (IsKeyPressed(KEY_BACKSPACE)) {
        InitializeGrid();
    }

}


std::string FormatText (const char *text, ...) {
    char buffer[1024] = { 0 };
    va_list args;
    va_start(args, text);
    vsprintf(buffer, text, args);
    va_end(args);
    return buffer;
}

void DisplayCount () {

    // count the number of rocks, sand and water 
    rockCount = 0;
    sandCount = 0;
    waterCount = 0;

    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == ROCK) rockCount++;
            else if (grid[i][j] == SAND) sandCount++;
            else if (grid[i][j] == WATER) waterCount++;
        }

    // Display the count
    DrawText(FormatText("Rocks: %i", rockCount), 10, 10, 20, BLACK);
    DrawText(FormatText("Sand: %i", sandCount), 10, 30, 20, BLACK);
    DrawText(FormatText("Water: %i", waterCount), 10, 50, 20, BLACK);

}

void UpdateGrid() {

    KeyPressHandeler();
    DisplayCount();

    // from bottom left to the top right
    for (int i= 0;i<GRID_SIZE;i++) {
        for ( int j = GRID_SIZE;j>0;j--) {
            if ( grid[i][j] == SAND) {
                if (grid[i][j+1] == EMPTY) {
                    grid[i][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i-1][j+1] == EMPTY) {
                    grid[i-1][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i+1][j+1] == EMPTY) {
                    grid[i+1][j+1] = SAND;
                    grid[i][j] = EMPTY;
                }
                    // add interaction with water 
                else if (grid[i][j+1] == WATER) {
                    grid[i][j+1] = SAND;
                    grid[i][j] = WATER;
                }
                else if (grid[i-1][j+1] == WATER) {
                    grid[i-1][j+1] = SAND;
                    grid[i][j] = WATER;
                }
                else if (grid[i+1][j+1] == WATER) {
                    grid[i+1][j+1] = SAND;
                    grid[i][j] = WATER;
                }
            }
            else if (grid[i][j] == WATER) {
                if (grid[i][j+1] == EMPTY) {
                    grid[i][j+1] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i-1][j] == EMPTY) {
                    grid[i-1][j] = WATER;
                    grid[i][j] = EMPTY;
                }
                else if (grid[i+1][j] == EMPTY) {
                    grid[i+1][j] = WATER;
                    grid[i][j] = EMPTY;
                }
                // check for downward diagonal 
               

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
                DrawBox (i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE, grid[i][j]);

        // Update the grid
        UpdateGrid();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

