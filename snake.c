#include "snake.h"
#include "game.h"

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
    Body tail = snake.parts[snake.length - 1]; // spara svansens position för att radera den senare
    tail.color = 0; // gör svansen osynlig    
    for (int i = snake.length - 1; i > 0; i--) {
        snake.parts[i] = snake.parts[i - 1];
    }
    snake.parts[0] = snake_next_head();
    if(apple_eaten() == 0){
        draw_block(tail); // radera svansen om vi inte ätit ett äpple   
    }
    }

void snake_hits_self(){
    for(int i = 2; i < snake.length; i++){
        if(snake.parts[0].x == snake.parts[i].x && snake.parts[0].y == snake.parts[i].y){
            gameIsOver = 1;

        } 
    }
} 
void snake_hits_wall(void){
    if(snake.parts[0].x > WIDTH - GRID_SIZE || snake.parts[0].x < GRID_SIZE ||
         snake.parts[0].y > HEIGHT - GRID_SIZE || snake.parts[0].y < GRID_SIZE){
        gameIsOver = 1;
    }
}
// ritar ut ormen på skärmen
void draw_snake(){
    for(int i = 0; i < snake.length; i++){
        draw_block(snake.parts[i]);
    }




    
    
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

