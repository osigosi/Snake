#include "game.h"
#include "snake.h"



Body apple;

int score = 0;
int gameIsOver = 0;

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

void game_init(void) {
    snake_init();
    draw_apple();
    score = 0;
    gameIsOver = 0;
}
void game_over(){
    snake_hits_self();
    snake_hits_wall();
    if(gameIsOver != 0 ){
         //skriva ut game over and scor
    }
     return;
}


