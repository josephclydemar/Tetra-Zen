#include <time.h>

#include "list.h"
#include "stack.h"

#ifndef GAME_H
#define GAME_H


typedef struct {
    void *activeBrick;
    clock_t brickFallSpeed;
    List *landedBlocks;
    Stack *completeLineBlocks;
} Game;


Game *GameCreate(void);
void GameActiveBrickLand(Game *game);
void GameActiveBrickCollide(Game *game);
clock_t GameUpdate(Game *game, clock_t timeInterval);
void GameDraw(Game *game);


#endif
