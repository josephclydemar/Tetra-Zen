#include "raylib.h"
#include "common.h"


#ifndef BLOCK_H
#define BLOCK_H


typedef struct {
    VectorInt2 pos;
    VectorInt2 size;
    Color color;
} Block;


Block *BlockCreate(int posX, int posY, Color color);
void BlockMoveLeft(Block *block);
void BlockMoveRight(Block *block);
void BlockDraw(Block *block);


#endif
