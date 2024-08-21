#include <stdlib.h>
#include "raylib.h"
#include "block.h"


Block *CreateBlock(int posX, int posY, Color color) {
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->pos.x = posX;
    newBlock->pos.y = posY;
    newBlock->size.x = 40;
    newBlock->size.y = 40;
    newBlock->color = color;
    return newBlock;
}

void MoveBlock(Block *block) {
    if(IsKeyDown(KEY_A)) {
        block->pos.x -= 40;
    }
    else if(IsKeyDown(KEY_D)) {
        block->pos.x += 40;
    }
}

void FallBlock(Block *block) {
    block->pos.y += 40;
}

void DeleteBlock(Block **block) {
    free(*block);
    *block = NULL;
}

void DrawBlock(Block *block) {
    DrawRectangle(block->pos.x, block->pos.y, block->size.x, block->size.y, block->color);
}

