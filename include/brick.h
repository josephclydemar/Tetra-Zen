#include "raylib.h"
#include "common.h"
#include "block.h"


#ifndef BRICK_H
#define BRICK_H


typedef enum {
    I_BRICK,
    O_BRICK,
    T_BRICK,
    J_BRICK,
    L_BRICK,
    S_BRICK,
    Z_BRICK,
} BrickType;

typedef struct {
    VectorInt2 pos;
    BrickType type;
    Block *blocks[4];
    Color color;
} Brick;


Brick *BrickCreate(BrickType brickType, int posX, int posY, Color color);
void BrickRotateCCW(Brick *brick);
void BrickRotateCW(Brick *brick);
void BrickDraw(Brick *brick);


#endif
