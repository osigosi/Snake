#include "config.h"
#ifndef SNAKE_H
#define SNAKE_H

typedef struct Body{
    int x;
    int y;
    int color;
} Body;

typedef struct Snake {
     Body parts[MAX_PART];  
    int length;
} Snake;


#endif
