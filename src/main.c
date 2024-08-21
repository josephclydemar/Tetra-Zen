#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "queue.h"
#include "common.h"
#include "block.h"

int main(void) {
    srand(time(0));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetra Zen");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second



    // Main game loop
    while(!WindowShouldClose()) {       // Detect window close button or ESC key

        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();                      // Close window and OpenGL context
    return 0;
}



