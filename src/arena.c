#include <time.h>
#include <stdlib.h>

#include "llist.h"
#include "stack.h"
#include "raylib.h"
#include "block.h"
#include "brick.h"
#include "arena.h"


#define FALL_TIME_UNIT_INTERVAL(x)     (clock_t)(CLOCKS_PER_SEC / x)


Arena *ArenaCreate(void) {
    Arena *newArena = (Arena*)malloc(sizeof(Arena));
    newArena->activeBrick = NULL;
    newArena->brickFallSpeed = 1;
    newArena->landedBlocks = CreateLList();
    newArena->completeLineBlocks = CreateStack();
    return newArena;
}


void ArenaActiveBrickLand(Arena *arena) {
    BrickLand((Brick*)(arena->activeBrick), arena->landedBlocks);
    arena->brickFallSpeed = 1;
    arena->activeBrick = (void*)BrickCreate(rand() % 7, rand() % 4, rand() % (GRID_VERTICAL_LINE_QUANTITY - 6) + 3, 2, BRICK_COLORS[rand() % 7]);
}


void ArenaActiveBrickCollide(Arena *arena) {
    int i;
    bool isEqualBlockPosX, isEqualBlockBottom;
    Brick *activeBrick = (Brick*)(arena->activeBrick);
    LList *landedBlocks = arena->landedBlocks;
    LNode *walker = landedBlocks->head;
    
    if(activeBrick->edges.bottom > 44) ArenaActiveBrickLand(arena);

    while(walker != NULL) {
        for(i = 0; i < BRICK_BLOCKS_COUNT; i++) {
            isEqualBlockPosX = activeBrick->blocks[i]->pos.x == ((Block*)(walker->data))->pos.x;
            isEqualBlockBottom = activeBrick->blocks[i]->pos.y + 1 == ((Block*)(walker->data))->pos.y;
            if(isEqualBlockPosX && isEqualBlockBottom) ArenaActiveBrickLand(arena);
        }
        walker = walker->next;
    }
}


clock_t ArenaUpdate(Arena *arena, clock_t timeInterval) {
    if(IsKeyPressed(KEY_SPACE)) arena->brickFallSpeed = 128;

    ArenaActiveBrickCollide(arena);
    if(clock() > timeInterval) {
        BrickDrop((Brick*)(arena->activeBrick));
        timeInterval = clock() + FALL_TIME_UNIT_INTERVAL(arena->brickFallSpeed);
    }
    return timeInterval;
}