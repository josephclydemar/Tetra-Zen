#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "raylib.h"
#include "queue.h"
#include "common.h"
#include "arena.h"
#include "brick.h"

int main(void) {
    //srand(time(0));

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetra Zen");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second

    Brick *myBricks[7] = {
        BrickCreate(I_BRICK, 0, 6, 2, RED),
        BrickCreate(L_BRICK, 0, 11,  7, YELLOW),
        BrickCreate(J_BRICK, 0, 16, 10, GREEN),
        BrickCreate(T_BRICK, 0, 21, 13, BLUE),
        BrickCreate(O_BRICK, 0, 26, 15, ORANGE),
        BrickCreate(S_BRICK, 0, 31, 18, PINK),
        BrickCreate(Z_BRICK, 0, 36, 22, VIOLET)
    };
    clock_t timeInterval = clock() + CLOCKS_PER_SEC;

    // Main game loop
    while(!WindowShouldClose()) {       // Detect window close button or ESC key
        //----------------------------------------------------------------------------------
        if(clock() > timeInterval) {
            for(int i = 0; i < 7; i++) {
                BrickFall(myBricks[i]);
            }
            timeInterval = clock() + CLOCKS_PER_SEC;
        }
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



