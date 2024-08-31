#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"
#include "common.h"
#include "arena.h"
#include "block.h"
#include "brick.h"


#define BRICK_BLOCK0_IN_MIDDLE_CONDITION      brick->blocks[0]->pos.x > 0 && brick->blocks[0]->pos.x + 1 < GRID_VERTICAL_LINE_QUANTITY
#define BRICK_IS_NOT_LANDED                   brick->edges.bottom < 45



/* Internal functions */
void _IBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 2;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case 1:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 2;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
        case 2:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 2;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
        case 3:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 2;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
    }
}

void _TBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[2]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case 1:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
        case 2:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[2]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
        case 3:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
    }
}

void _JBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case 1:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[2]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case 2:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
        case 3:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[2]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
    }
}

void _LBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0: /* at 0deg */
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case 1: /* at 90deg */
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;
            
            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;
            
            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[2]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
        case 2: /* at 180deg */
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;
            
            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
        case 3: /* at 270deg */
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[2]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
    }
}

void _SBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case 1:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[2]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case 2:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
        case 3:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[2]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
    }
}

void _ZBrickOrient(Brick *brick) {
    switch(brick->orient) {
        case 0:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[1]->pos.x;
            brick->edges.right = brick->blocks[3]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case 1:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[0]->pos.x;
            brick->edges.right = brick->blocks[2]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[1]->pos.y + GRID_CELL_SIZE;
            break;
        case 2:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x + 1;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->edges.left = brick->blocks[3]->pos.x;
            brick->edges.right = brick->blocks[1]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[0]->pos.y + GRID_CELL_SIZE;
            break;
        case 3:
            brick->blocks[0]->pos.x = brick->pos.x;
            brick->blocks[0]->pos.y = brick->pos.y;

            brick->blocks[1]->pos.x = brick->blocks[0]->pos.x;
            brick->blocks[1]->pos.y = brick->blocks[0]->pos.y - 1;

            brick->blocks[2]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[2]->pos.y = brick->blocks[0]->pos.y;

            brick->blocks[3]->pos.x = brick->blocks[0]->pos.x - 1;
            brick->blocks[3]->pos.y = brick->blocks[0]->pos.y + 1;

            brick->edges.left = brick->blocks[2]->pos.x;
            brick->edges.right = brick->blocks[0]->pos.x + GRID_CELL_SIZE;
            brick->edges.top = brick->blocks[0]->pos.y;
            brick->edges.bottom = brick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
    }
}


void _BrickOrientByType(Brick *brick) {
    switch(brick->type) {
        case I_BRICK:
            _IBrickOrient(brick);
            break;
        case O_BRICK:
            break;
        case T_BRICK:
            _TBrickOrient(brick);
            break;
        case J_BRICK:
            _JBrickOrient(brick);
            break;
        case L_BRICK:
            _LBrickOrient(brick);
            break;
        case S_BRICK:
            _SBrickOrient(brick);
            break;
        case Z_BRICK:
            _ZBrickOrient(brick);
            break;
    }
}


void _BrickDestroy(Brick *brick) {
    free(brick);
}


/* **************** */


Brick *BrickCreate(EBrickType brickType, int orient, int posX, int posY, Color color) {
    Brick *newBrick = (Brick*)malloc(sizeof(Brick));

    newBrick->orient = orient;
    newBrick->pos.x = posX;
    newBrick->pos.y = posY;
    newBrick->type = brickType;
    newBrick->color = color;

    switch(newBrick->type) {
        case I_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y - 1,  newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 2,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[0]->pos.x;
            newBrick->edges.right = newBrick->blocks[0]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case O_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y,      newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[0]->pos.x;
            newBrick->edges.right = newBrick->blocks[1]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case T_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x - 1,  newBrick->blocks[0]->pos.y,      newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y,      newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[1]->pos.x;
            newBrick->edges.right = newBrick->blocks[2]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[3]->pos.y + GRID_CELL_SIZE;
            break;
        case J_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y - 1,  newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x - 1,  newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[3]->pos.x;
            newBrick->edges.right = newBrick->blocks[0]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case L_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y - 1,  newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[0]->pos.x;
            newBrick->edges.right = newBrick->blocks[3]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case S_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y,      newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x - 1,  newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[3]->pos.x;
            newBrick->edges.right = newBrick->blocks[1]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
        case Z_BRICK:
            newBrick->blocks[0] = BlockCreate(newBrick->pos.x,                 newBrick->pos.y,                 newBrick->color);
            newBrick->blocks[1] = BlockCreate(newBrick->blocks[0]->pos.x - 1,  newBrick->blocks[0]->pos.y,      newBrick->color);
            newBrick->blocks[2] = BlockCreate(newBrick->blocks[0]->pos.x,      newBrick->blocks[0]->pos.y + 1,  newBrick->color);
            newBrick->blocks[3] = BlockCreate(newBrick->blocks[0]->pos.x + 1,  newBrick->blocks[0]->pos.y + 1,  newBrick->color);

            newBrick->edges.left = newBrick->blocks[1]->pos.x;
            newBrick->edges.right = newBrick->blocks[3]->pos.x + GRID_CELL_SIZE;
            newBrick->edges.top = newBrick->blocks[0]->pos.y;
            newBrick->edges.bottom = newBrick->blocks[2]->pos.y + GRID_CELL_SIZE;
            break;
    }
    _BrickOrientByType(newBrick);
    return newBrick;
}


void BrickMoveLeft(Brick *brick) {
    if(BRICK_IS_NOT_LANDED && brick->edges.left > 0) {
        brick->pos.x--;
        for(int i = 0; i < 4; i++) {
            brick->blocks[i]->pos.x--;
        }
        brick->edges.left--;
        brick->edges.right--;
    }
}

void BrickMoveRight(Brick *brick) {
    if(BRICK_IS_NOT_LANDED && brick->edges.right < GRID_VERTICAL_LINE_QUANTITY + 14) {
        brick->pos.x++;
        for(int i = 0; i < 4; i++) {
            brick->blocks[i]->pos.x++;
        }
        brick->edges.left++;
        brick->edges.right++;
    }
}

/*
void BrickCollide(Brick *brick) {
}
*/

void BrickRotateCCW(Brick *brick) {
    if(BRICK_IS_NOT_LANDED && BRICK_BLOCK0_IN_MIDDLE_CONDITION) {
        brick->orient++;
        if(brick->orient > 3) {
            brick->orient = 0;
        }
        _BrickOrientByType(brick);
    }
}

void BrickRotateCW(Brick *brick) {
    if(BRICK_IS_NOT_LANDED && BRICK_BLOCK0_IN_MIDDLE_CONDITION) {
        brick->orient--;
        if(brick->orient < 0) {
            brick->orient = 3;
        }
        _BrickOrientByType(brick);
    }
}


bool BrickFall(Brick *brick) {
    int i;
    if(BRICK_IS_NOT_LANDED) {
        brick->pos.y++;
        for(i = 0; i < 4; i++) {
            brick->blocks[i]->pos.y++;
        }
        brick->edges.bottom++;
        return false;
    }
    return true;
}


void BrickDraw(Brick *brick) {
    if(IsKeyPressed(KEY_A)) {
        BrickMoveLeft(brick);
    }else if(IsKeyPressed(KEY_D)) {
        BrickMoveRight(brick);
    }

    if(IsKeyPressed(KEY_Q)) {
        BrickRotateCCW(brick);
    }
    else if(IsKeyPressed(KEY_E)) {
        BrickRotateCW(brick);
    }

    for(int i = 0; i < 4; i++) {
        BlockDraw(brick->blocks[i]);
    }
}


void BrickLand(Arena *arena) {
    for(int i = 0; i < 4; i++) {
        LListInsert(arena->landedBlocks, 0, (void*)(((Brick*)(arena->activeBrick))->blocks[i]));
    }
    _BrickDestroy((Brick*)(arena->activeBrick));
    arena->activeBrick = (void*)BrickCreate(rand() % 7, rand() % 4, rand() % GRID_VERTICAL_LINE_QUANTITY, 2, BrickColors[rand() % 7]);
}


