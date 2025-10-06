#include "hardware.h"
#include "game.h"
#include "snake.h"
#include "graphics.h"
#include <stdio.h>

volatile int* const timer_status  = (volatile int*)0x04000020;
volatile int* const interrupt = (volatile int*)0x04000012;
volatile int* const edgecapture   = (volatile int*)0x040000013;
volatile int* const switches      = (volatile int*)0x04000010;

volatile int* const periodL      = (volatile int*)0x04000028;
volatile int* const periodH      = (volatile int*)0x0400002C;
volatile int* const timerControl = (volatile int*)0x04000024;



int timeoutcount = 0; // räknar hur många gånger timern har gått ut 

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{ 
    if(*timer_status & 0x1){
      *timer_status = 0; // visa att timeout hänt och nollställer de
      timeoutcount++; // ökar för varje timout som händer 
      if (timeoutcount >= 10) { // loopen är basically att när 10 hänt då en sekund och då öka 7 segmentet
          timeoutcount = 0;
          *interrupt = 0;
          int sw = *switches & 0x55;
          snake_set_dir(sw); // sätt riktning beroende på switcharna

          snake_move();
          snake_hits_self();
          snake_hits_wall();
        }
    }
}

extern void enable_interrupt(); // för att kunna användas ghär från boot.s
/* Add your code here for initializing interrupts. */


void labinit(void)
{

    *interrupt = 85; //tilllåter intrupt från 01010101 dvs sw6 = N, sw4 = S, sw2 = W, sw0 = E
    
    *periodL = (2999999) &0xFFFF;
    *periodH = (2999999 >> 16); // 30MHz 0.1 100ms

    // Starta timern: start=1, CONT=1, ITO=1
    *timerControl = (1<<2) | (1<<1) | (1<<0); // sätter controll bitar till ett 
    
    //cont- behöver ej starta manuellt , ito- så avbrott när noll och får signal om det, start- startar timer
    enable_interrupt(); // från boot.S
}
