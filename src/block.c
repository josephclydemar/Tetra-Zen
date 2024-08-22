#include <stdlib.h>
#include "arena.h"
#include "block.h"


Block *BlockCreate(int posX, int posY, Color color) {
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->pos.x = posX;
    newBlock->pos.y = posY;
    newBlock->size.x = GRID_CELL_SIZE;
    newBlock->size.y = GRID_CELL_SIZE;
    newBlock->color = color;
    return newBlock;
}

void BlockMoveLeft(Block *block) {
    block->pos.x -= GRID_CELL_SIZE;
}

void BlockMoveRight(Block *block) {
    block->pos.x += GRID_CELL_SIZE;
}

void BlockDraw(Block *block) {
    DrawRectangle(
            block->pos.x * GRID_CELL_SIZE + GRID_START_POS_X, 
            block->pos.y * GRID_CELL_SIZE + GRID_START_POS_Y, 
            block->size.x, 
            block->size.y, 
            block->color);
}




