#include "graphics.h"


// definierar själva variabeln till vga basen (bara en gång i hela projektet)
volatile char *VGA = (volatile char*) 0x08000000;

void draw_grid(void) {
    for(int x = 0; x < WIDTH; x += GRID_SIZE){
        for(int y = 0; y < HEIGHT; y++){
        VGA[y * 320 + x] = "#FFF";
        }
    }
}

void reset_screen(void) {
    // ...
}

void draw_block(Body body) {
        for( int i = body.x *GRID_SIZE ; i >= body.x *GRID_SIZE - 20; i--){
            for(int j = body.y *GRID_SIZE ; j >= body.y *GRID_SIZE - 20; j--){
                VGA[j * 320 + i] = body.color;
            }
        }

    }
