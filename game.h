#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "snake.h"
#include "graphics.h"
// håller koll på hut många poäng vi har, ska öka när vi äter ett äpple
extern int score;
// håller koll på hut många poäng vi har, ska öka när vi äter ett äpple
extern int gameIsOver; // vi behöver bestämma om detta ska vara ett interrupt

// Skriver ut äpplet i röd färg på en slumpmässig plats på gameboarden
void draw_apple();

// Kollar om vi har ätit ett äpple genom att jämföra äpplets position med huvudet
int apple_eaten();


void game_over();

void draw_score();

#endif