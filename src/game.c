#include <time.h>
#include <stdlib.h>

#include "llist.h"
#include "stack.h"
#include "raylib.h"
#include "block.h"
#include "brick.h"
#include "game.h"


#define FALL_TIME_UNIT_INTERVAL(x)     (clock_t)(CLOCKS_PER_SEC / x)


Game *GameCreate(void) {
    Game *newGame = (Game*)malloc(sizeof(Game));
    newGame->activeBrick = NULL;
    newGame->brickFallSpeed = 1;
    newGame->landedBlocks = CreateLList();
    newGame->completeLineBlocks = CreateStack();
    return newGame;
}


void GameActiveBrickLand(Game *game) {
    BrickLand((Brick*)(game->activeBrick), game->landedBlocks);
    game->brickFallSpeed = 1;
    game->activeBrick = (void*)BrickCreate(rand() % 7, rand() % 4, rand() % (GRID_VERTICAL_LINE_QUANTITY - 6) + 3, 2, BRICK_COLORS[rand() % 7]);
}


void GameActiveBrickCollide(Game *game) {
    int i;
    bool isEqualBlockPosX, isEqualBlockBottom;
    Brick *activeBrick = (Brick*)(game->activeBrick);
    LList *landedBlocks = game->landedBlocks;
    LNode *walker = landedBlocks->head;
    
    if(activeBrick->edges.bottom > 44) GameActiveBrickLand(game);

    while(walker != NULL) {
        for(i = 0; i < BRICK_BLOCKS_COUNT; i++) {
            isEqualBlockPosX = activeBrick->blocks[i]->pos.x == ((Block*)(walker->data))->pos.x;
            isEqualBlockBottom = activeBrick->blocks[i]->pos.y + 1 == ((Block*)(walker->data))->pos.y;
            if(isEqualBlockPosX && isEqualBlockBottom) GameActiveBrickLand(game);
        }
        walker = walker->next;
    }
}


clock_t GameUpdate(Game *game, clock_t timeInterval) {
    if(IsKeyPressed(KEY_SPACE)) game->brickFallSpeed = 128;

    GameActiveBrickCollide(game);
    if(clock() > timeInterval) {
        BrickDrop((Brick*)(game->activeBrick));
        timeInterval = clock() + FALL_TIME_UNIT_INTERVAL(game->brickFallSpeed);
    }
    return timeInterval;
}