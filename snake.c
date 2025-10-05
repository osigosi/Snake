#include "snake.h"

Snake snake;

void snake_init(void){
    snake.parts[0] = (Body){2*GRID_SIZE, 2*GRID_SIZE, 1};
    snake.parts[1] = (Body){1*GRID_SIZE, 1*GRID_SIZE, 1};
    snake.length = 2;
} 

int snake_dir(void){
     if(snake.parts[0].x <  snake.parts[1].x) // if snake is in west direction
        return DIR_W;
    if(snake.parts[0].x > snake.parts[1].x) // if snake moves i east
        return DIR_E;
    if(snake.parts[0].y < snake.parts[1].y) // if snake moves in north
        return DIR_N;
    if(snake.parts[0].y > snake.parts[1].y) // if snake moves in south
        return DIR_S;
}
Body snake_next_head(void){
    int direction = snake_current_dir();
   Body head; 
    switch (direction)
    {
    case DIR_E:
        head = (Body){snake.parts[0].x + 1*GRID_SIZE ,snake.parts[0].y , snake.parts[0].color};
        break;
    case DIR_W:
        head = (Body){snake.parts[0].x - 1*GRID_SIZE ,snake.parts[0].y, snake.parts[0].color};
        break;
    case DIR_N:
        head = (Body){snake.parts[0].x,snake.parts[0].y - 1*GRID_SIZE, snake.parts[0].color};
        break;
    case DIR_S:
        head = (Body){snake.parts[0].x,snake.parts[0].y + 1*GRID_SIZE, snake.parts[0].color};
        break;
    default:
        break;
    }
    return head;

}
void snake_move(void){ // west = 0x4, east = 0x1, north = 0x40 south = 0x10
    for (int i = snake.length - 1; i > 0; i--) {
        snake.parts[i] = snake.parts[i - 1];
    }
    snake.parts[0] = snake_next_head();
    }

void draw_snake();




    
    
    /*if(direction == 0x1 )
        body head = {snake.parts[0].x + 20,snake.parts[0].y , snake.parts[0].color};
    if(direction == 0x4 )
        body head = {snake.parts[0].x - 20 ,snake.parts[0].y, snake.parts[0].color};
    if(direction == 0x10 )
        body head = {snake.parts[0].x,snake.parts[0].y + 20, snake.parts[0].color};
    if(direction == 0x40 )
        body head = {snake.parts[0].x,snake.parts[0].y - 20 , snake.parts[0].color};
    
    for (int i = snake.length - 1; i > 0; i--) {
        snake.parts[i] = snake.parts[i - 1];
    }
    snake.parts[0] = head;*/

