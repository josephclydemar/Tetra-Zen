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


Arena *ArenaCreate(void);

void ArenaActiveBrickLand(Arena *arena);

void ArenaActiveBrickCollide(Arena *arena);

clock_t ArenaSomething(Arena *arena, clock_t timeInterval);

#endif
