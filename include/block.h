#include "common.h"

#ifndef BLOCK_H
#define BLOCK_H


typedef struct {
    VectorInt2 pos;
    VectorInt2 size;
    Color color;
} Block;


Block *CreateBlock(int posX, int posY, Color color);
void MoveBlock(Block *boid);
void FallBlock(Block *boid);
void DeleteBlock(Block **boid);
void DrawBlock(Block *boid);

#endif


