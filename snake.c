#include "snake.h"
#include "game.h"

#define SNAKE_BASE 0x00000020 // minnes adress där ormen börjar 


// Vi deklarerar ormen här
Snake snake;

void snake_init(void){
    snake.parts = (Body*)SNAKE_BASE; // allokera minne för ormen
    snake.parts[0] = (Body){2*GRID_SIZE, 2*GRID_SIZE, 1};
    snake.parts[1] = (Body){1*GRID_SIZE, 1*GRID_SIZE, 1};
    snake.length = 2; 
    current_dir = DIR_E;
} 

int snake_dir(void){
    return current_dir;
}

Body snake_next_head(void){
    Body head = snake.parts[0];

    switch (current_dir)
    {
    case DIR_E:
        head.x += GRID_SIZE;
        break;
    case DIR_W:
        head.x -= GRID_SIZE;
        break;
    case DIR_N:
        head.y -= GRID_SIZE;
        break;
    case DIR_S:
        head.y += GRID_SIZE;
        break;
    default:
        break;
    }

    head.color = snake.parts[0].color;
    return head;

}
void snake_set_dir(int dir){
    int both = dir | current_dir;
    if (both == (DIR_E | DIR_W) || both == (DIR_N | DIR_S)){
        return;
      }

    current_dir = dir;
}
// flyttar ormen i den riktning som är satt och kollar om vi ätit ett äpple
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

