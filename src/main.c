#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "queue.h"
#include "common.h"
#include "arena.h"
#include "brick.h"

int main(void) {
    srand(time(0));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetra Zen");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second

    Brick *myBricks[7] = {
        BrickCreate(I_BRICK, 25, 3, RED),
        BrickCreate(T_BRICK, 3, 5, YELLOW),
        BrickCreate(O_BRICK, 7, 7, GREEN),
        BrickCreate(J_BRICK, 12, 6, BLUE),
        BrickCreate(L_BRICK, 14, 5, ORANGE),
        BrickCreate(S_BRICK, 17, 17, MAROON),
        BrickCreate(Z_BRICK, 25, 13, VIOLET)
    };


    // Main game loop
    while(!WindowShouldClose()) {       // Detect window close button or ESC key

        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0; i < 7; i++) {
            BrickDraw(myBricks[i]);
        }
        GridDraw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();                      // Close window and OpenGL context
    return 0;
}



