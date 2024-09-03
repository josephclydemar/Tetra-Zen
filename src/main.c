#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "raylib.h"
#include "queue.h"
#include "common.h"
#include "arena.h"
#include "block.h"
#include "brick.h"


#define FALL_TIME_UNIT_INTERVAL(x)     (clock_t)(CLOCKS_PER_SEC / x)


int main(void) {
    srand(time(0));
    Arena *GameArena = CreateArena();
    GameArena->activeBrick = (void*)BrickCreate(L_BRICK, 0, (int)(GRID_VERTICAL_LINE_QUANTITY / 2), 2, BRICK_COLORS[0]);
    LNode *walker = GameArena->landedBlocks->head;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetra Zen");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    clock_t timeInterval = clock() + CLOCKS_PER_SEC;

    // Main game loop
    while(!WindowShouldClose()) {       // Detect window close button or ESC key
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_SPACE)) GameArena->brickFallSpeed = 128;

        BrickCollide(GameArena);
        if(clock() > timeInterval) {
            BrickDrop(GameArena);
            timeInterval = clock() + FALL_TIME_UNIT_INTERVAL(GameArena->brickFallSpeed);
        }
        BeginDrawing();
        ClearBackground(BLACK);

        BrickDraw(GameArena);

        walker = GameArena->landedBlocks->head;
        while(walker != NULL) {
            BlockDraw((Block*)(walker->data));
            walker = walker->next;
        }
        
        GridDraw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();                      // Close window and OpenGL context
    return 0;
}



