#include "raylib.h"
#include "arena.h"

void GridDraw(void) {
    int i;
    /* Draw the vertical grid lines */
    for(i = 0; i < GRID_VERTICAL_LENGTH + 1; i++) {
        DrawLine(
                GRID_START_POS_X + i * GRID_CELL_SIZE,                      GRID_START_POS_Y, 
                GRID_START_POS_X + i * GRID_CELL_SIZE,                      GRID_START_POS_Y + GRID_HORIZONTAL_LENGTH * GRID_CELL_SIZE, 
                GRAY);
    }

    /* Draw the horizontal grid lines */
    for(i = 0; i < GRID_HORIZONTAL_LENGTH + 1; i++) {
        DrawLine(
                GRID_START_POS_X,                                           GRID_START_POS_Y + i * GRID_CELL_SIZE,
                GRID_START_POS_X + GRID_VERTICAL_LENGTH * GRID_CELL_SIZE,   GRID_START_POS_Y + i * GRID_CELL_SIZE,
                GRAY);
    }
}
