#include <time.h>

#include "llist.h"
#include "stack.h"

#ifndef ARENA_H
#define ARENA_H


typedef struct {
    void *activeBrick;
    clock_t brickFallSpeed;
    LList *landedBlocks;
    Stack *completeLineBlocks;
} Arena;


Arena *CreateArena(void);


#endif
