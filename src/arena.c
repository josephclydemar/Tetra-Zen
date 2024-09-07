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


