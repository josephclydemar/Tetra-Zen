#include "raylib.h"
#include "common.h"

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
