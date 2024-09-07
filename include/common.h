
#ifndef COMMON_H
#define COMMON_H


#define WINDOW_WIDTH                        1200
#define WINDOW_HEIGHT                       600

#define GRID_START_POS_X                    80
#define GRID_START_POS_Y                    50

#define GRID_VERTICAL_LINE_QUANTITY         70
#define GRID_HORIZONTAL_LINE_QUANTITY       31
#define GRID_CELL_SIZE                      15

typedef struct {
    int x;
    int y;
} VectorInt2;

typedef struct {
    float x;
    float y;
} VectorFloat2;


void GridDraw(void);


#endif


