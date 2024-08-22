#include <stdlib.h>

#include "raylib.h"
#include "common.h"
#include "arena.h"
#include "block.h"
#include "brick.h"


Brick *BrickCreate(BrickType brickType, int posX, int posY, Color color) {
    Brick *newBrick = (Brick*)malloc(sizeof(Brick));
    newBrick->pos.x = posX;
    newBrick->pos.y = posY;
    newBrick->color = color;

    switch(brickType) {
        case I_BRICK:
            newBrick->type = I_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y - 1, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 2, color);
            break;
        case O_BRICK:
            newBrick->type = O_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y + 1, color);
            break;
        case T_BRICK:
            newBrick->type = T_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x - 1, newBrick->blocks[0]->pos.y, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            break;
        case J_BRICK:
            newBrick->type = J_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y - 1, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x - 1, newBrick->blocks[0]->pos.y + 1, color);
            break;
        case L_BRICK:
            newBrick->type = L_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y - 1, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y + 1, color);
            break;
        case S_BRICK:
            newBrick->type = S_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x - 1, newBrick->blocks[0]->pos.y + 1, color);
            break;
        case Z_BRICK:
            newBrick->type = Z_BRICK;
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x, newBrick->pos.y, color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x - 1, newBrick->blocks[0]->pos.y, color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x, newBrick->blocks[0]->pos.y + 1, color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1, newBrick->blocks[0]->pos.y + 1, color);
            break;
    }

    return newBrick;
}

void BrickMoveLeft(Brick *brick) {
    for(int i = 0; i < 4; i++) {
        brick->blocks[i]->pos.x--;
    }
}

void BrickMoveRight(Brick *brick) {
    for(int i = 0; i < 4; i++) {
        brick->blocks[i]->pos.x++;
    }
}

//void BrickRotateCCW(Brick *brick);
//void BrickRotateCW(Brick *brick);

void BrickDraw(Brick *brick) {
    if(IsKeyPressed(KEY_A)) {
        BrickMoveLeft(brick);
    }
    else if(IsKeyPressed(KEY_D)) {
        BrickMoveRight(brick);
    }

    for(int i = 0; i < 4; i++) {
        BlockDraw(brick->blocks[i]);
    }
}


