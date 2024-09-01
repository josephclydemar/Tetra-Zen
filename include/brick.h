#include <stdbool.h>

#include "queue.h"
#include "raylib.h"
#include "common.h"
#include "arena.h"
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
    Queue otherBricks;
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
void BrickCollide(Arena *arena);

/*
 * @param brick: Memory address of the Brick to drop
 * */
void BrickDrop(Arena *arena);

/*
 * @param brick: Memory address of the Brick to draw
 * */
void BrickDraw(Arena *arena);


#endif
