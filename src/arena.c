#include <stdlib.h>

#include "llist.h"
#include "stack.h"
#include "raylib.h"
#include "arena.h"


Arena *CreateArena(void) {
    Arena *newArena = (Arena*)malloc(sizeof(Arena));
    newArena->activeBrick = NULL;
    newArena->brickFallSpeed = 1;
    newArena->landedBlocks = CreateLList();
    newArena->completeLineBlocks = CreateStack();
    return newArena;
}


void GridDraw(void) {
    int i;
    /* Draw the vertical grid lines */
    for(i = 0; i < GRID_VERTICAL_LINE_QUANTITY + 1; i++) {
        DrawLine(
                GRID_START_POS_X + i * GRID_CELL_SIZE,                      GRID_START_POS_Y, 
                GRID_START_POS_X + i * GRID_CELL_SIZE,                      GRID_START_POS_Y + GRID_HORIZONTAL_LINE_QUANTITY * GRID_CELL_SIZE, 
                GRAY);
    }

    /* Draw the horizontal grid lines */
    for(i = 0; i < GRID_HORIZONTAL_LINE_QUANTITY + 1; i++) {
        DrawLine(
                GRID_START_POS_X,                                           GRID_START_POS_Y + i * GRID_CELL_SIZE,
                GRID_START_POS_X + GRID_VERTICAL_LINE_QUANTITY * GRID_CELL_SIZE,   GRID_START_POS_Y + i * GRID_CELL_SIZE,
                GRAY);
    }
}
