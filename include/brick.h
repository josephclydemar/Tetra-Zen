#include <stdbool.h>

#include "llist.h"
#include "raylib.h"
#include "common.h"
#include "block.h"


#ifndef BRICK_H
#define BRICK_H


#define BRICK_BLOCKS_COUNT      4

const Color BRICK_COLORS[7] = { ORANGE, RED, VIOLET, BEIGE, BLUE, PINK, GREEN };

typedef enum {
    I_BRICK,
    O_BRICK,
    T_BRICK,
    J_BRICK,
    L_BRICK,
    S_BRICK,
    Z_BRICK,
} EBrickType;


typedef struct {
    int top;
    int bottom;
    int left;
    int right;
} BrickEdge;

typedef struct {
    int orient;
    VectorInt2 pos;
    BrickEdge edges;
    EBrickType type;
    Block *blocks[BRICK_BLOCKS_COUNT];
    Color color;
} Brick;

/*
 * @param brickType: Type of Brick to create
 * @param orient: Initial orientation of the Brick to create
 * @param posX: Initial x-axis position of the Brick to create
 * @param posY: Initial y-axis position of the Brick to create
 * @param color: Color of the brick to create
 * @return: Memory address of the created Brick
 * */
Brick *BrickCreate(EBrickType brickType, int orient, int posX, int posY, Color color);

/*
 * @param brick: Memory address of the Brick to fall
 * */
void BrickLand(Brick *brick, LList *landedBlocks);

/*
 * @param brick: Memory address of the Brick to drop
 * */
void BrickDrop(Brick *brick);

/*
 * @param brick: Memory address of the Brick to draw
 * */
void BrickDraw(Brick *brick, LList *landedBlocks);


#endif
