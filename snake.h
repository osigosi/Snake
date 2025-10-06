#include "config.h"
#ifndef SNAKE_H
#define SNAKE_H

#define DIR_E 0x01
#define DIR_W 0x04
#define DIR_S 0x10
#define DIR_N 0x40

#define SNAKE_BASE = 0x00000020

extern volatile int current_dir;

typedef struct Body{
    int x;
    int y;
    int color;
} Body;

typedef struct Snake {
     Body *parts;  
     int length;
} Snake;

extern Snake snake; // vi deklarerar ormen på annat ställe
void snake_init(void); 

Body snake_next_head(void);

void snake_move(void);

void snake_hits_self(void); 

void snake_hits_wall(void); 

void snake_grow(void);

int snake_dir(void);

void snake_set_dir(int dir);

void snake_draw(void); 

extern Snake snake; // så vi har tillgång till ormen i alla filer

#endif
