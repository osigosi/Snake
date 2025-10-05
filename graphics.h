
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "config.h"
#include "snake.h"
// global pekare till vga basen
extern volatile char *VGA;

void draw_grid();
void reset_screen();
void draw_block(Body body);

#endif