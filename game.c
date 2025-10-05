#include "game.h"
#include "snake.h"

Snake snake;

Body apple;

int score = 0;
int gameIsover = 0;

void draw_apple(void) {
    // placera äpplet random på rutnätet (inte för utanför kanterna)
    apple.x = ((rand() % ((WIDTH - 3 * GRID_SIZE) / GRID_SIZE)) + 1) * GRID_SIZE;
    apple.y = ((rand() % ((HEIGHT - 3 * GRID_SIZE) / GRID_SIZE)) + 1) * GRID_SIZE;
    apple.color = "RED"; // måste definieras
    draw_block(apple);
}

int apple_eaten(void) {
    if (snake.parts[0].x == apple.x && snake.parts[0].y == apple.y) {
        score++;
        snake.length++;
        draw_apple();
        return 1;
    }
    return 0;
}

void grid_collision(){
    if(snake.parts[0].x > WIDTH - GRID_SIZE || snake.parts[0].x < GRID_SIZE ||
         snake.parts[0].y > HEIGHT - GRID_SIZE || snake.parts[0].y < GRID_SIZE){
        gameIsover = 1;
    }
}
void snake_collision(){
    for(int i = 2; i < snake.length; i++){
        if(snake.parts[0].x == snake.parts[i].x && snake.parts[0].y == snake.parts[i].y){
            gameIsover = 1;

        } 
    }
} 

void game_over(){
    grid_collision();
    snake_collision();
    if(gameIsover != 0 ){
         //skriva ut game over and scor
    }
     return;
}


