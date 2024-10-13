#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "raylib.h"
#include "common.h"
#include "game.h"


int main(void) {
    srand(time(0));
    Game* game = GameCreate();

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetra Zen");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    clock_t timeInterval = clock() + CLOCKS_PER_SEC;

    // Main game loop
    while(!WindowShouldClose()) {       // Detect window close button or ESC key
        timeInterval = GameUpdate(game, timeInterval);
        
        BeginDrawing();
        ClearBackground(BLACK);

        GameDraw(game);
        
        GridDraw();
        EndDrawing();
    }
    CloseWindow();                      // Close window and OpenGL context
    return 0;
}



