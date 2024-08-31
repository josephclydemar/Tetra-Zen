#include <stdlib.h>
#include "arena.h"
#include "block.h"


Block *BlockCreate(int posX, int posY, Color color) {
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->pos.x = posX;
    newBlock->pos.y = posY;
    newBlock->size.x = GRID_CELL_SIZE;
    newBlock->size.y = GRID_CELL_SIZE;
    
    newBlock->highlight[0].x = newBlock->pos.x * GRID_CELL_SIZE + 2 + GRID_START_POS_X;
    newBlock->highlight[0].y = (newBlock->pos.y + 1) * GRID_CELL_SIZE - 2 + GRID_START_POS_Y;

    newBlock->highlight[1].x = newBlock->pos.x * GRID_CELL_SIZE + 2 + GRID_START_POS_X;
    newBlock->highlight[1].y = newBlock->pos.y * GRID_CELL_SIZE + 2 + GRID_START_POS_Y;
    
    newBlock->highlight[2].x = (newBlock->pos.x + 1) * GRID_CELL_SIZE - 2 + GRID_START_POS_X;
    newBlock->highlight[2].y = newBlock->pos.y * GRID_CELL_SIZE + 2 + GRID_START_POS_Y;


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
    block->highlight[0].x = block->pos.x * GRID_CELL_SIZE + 2 + GRID_START_POS_X;
    block->highlight[0].y = (block->pos.y + 1) * GRID_CELL_SIZE - 2 + GRID_START_POS_Y;

    block->highlight[1].x = block->pos.x * GRID_CELL_SIZE + 2 + GRID_START_POS_X;
    block->highlight[1].y = block->pos.y * GRID_CELL_SIZE + 2 + GRID_START_POS_Y;
    
    block->highlight[2].x = (block->pos.x + 1) * GRID_CELL_SIZE - 2 + GRID_START_POS_X;
    block->highlight[2].y = block->pos.y * GRID_CELL_SIZE + 2 + GRID_START_POS_Y;


    DrawRectangle(
            block->pos.x * GRID_CELL_SIZE + GRID_START_POS_X, 
            block->pos.y * GRID_CELL_SIZE + GRID_START_POS_Y, 
            block->size.x, 
            block->size.y, 
            block->color);
    DrawSplineLinear(block->highlight, 3, 1.0f, WHITE);
}




