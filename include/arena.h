#include "llist.h"
#include "stack.h"

#ifndef ARENA_H
#define ARENA_H


#define GRID_START_POS_X            80
#define GRID_START_POS_Y            50

#define GRID_VERTICAL_LINE_QUANTITY        70
#define GRID_HORIZONTAL_LINE_QUANTITY      31
#define GRID_CELL_SIZE              15


typedef struct {
    void *activeBrick;
    LList *landedBlocks;
    Stack *completeLineBlocks;
} Arena;

Arena *CreateArena(void);


void GridDraw(void);


#endif
