#include "snake.h"

static Snake snake;

void snake_init(void){
    snake.parts[0] = (Body){2*GRID_SIZE, 2*GRID_SIZE, 1};
    snake.parts[1] = (Body){1*GRID_SIZE, 1*GRID_SIZE, 1};
    snake.length = 2;
} 