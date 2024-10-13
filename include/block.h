

#ifndef BLOCK_H
#define BLOCK_H

#include "raylib.h"
#include "common.h"


typedef struct {
    VectorInt2 pos;
    VectorInt2 size;
    Vector2 highlight[3];
    Color color;
} Block;


Block* BlockCreate(int posX, int posY, Color color);
void BlockMoveLeft(Block* block);
void BlockMoveRight(Block* block);
void BlockDraw(Block* block);


#endif
