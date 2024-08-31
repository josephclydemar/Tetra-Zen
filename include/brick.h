#include <stdbool.h>

#include "queue.h"
#include "raylib.h"
#include "common.h"
#include "arena.h"
#include "block.h"


#ifndef BRICK_H
#define BRICK_H


const Color BrickColors[7] = { ORANGE, RED, VIOLET, BEIGE, BLUE, PINK, GREEN };

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
    Block *blocks[4];
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
 * @param brick: Memory address of the Brick
 * */
void BrickCollide(Brick *brick);

/*
 * @param brick: Memory address of the Brick to rotate counter-clockwise
 * */
void BrickRotateCCW(Brick *brick);

/*
 * @param brick: Memory address of the Brick to rotate clockwise
 * */
void BrickRotateCW(Brick *brick);

/*
 * @param brick: Memory address of the Brick to fall
 * */
bool BrickFall(Brick *brick);

/*
 * @param brick: Memory address of the Brick to draw
 * */
void BrickDraw(Brick *brick);

/*
 * @param brick: Memory address of the Brick to draw
 * */
void BrickLand(Arena *arena);


#endif
