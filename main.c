#include "hardware.h"
#include "game.h"
#include "snake.h"
#include "graphics.h"
#include <stdio.h>

int timeoutcount = 0; // räknar hur många gånger timern har gått ut 

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{
    if(TIMER_STATUS & 0x1){
      TIMER_STATUS = 0; // visa att timeout hänt och nollställer de
      timeoutcount++; // ökar för varje timout som händer 
      if (timeoutcount >= 10) { // loopen är basically att när 10 hänt då en sekund och då öka 7 segmentet
          timeoutcount = 0;


      if((SWITCHES & 0x55) == DIR_E && snake_dir() != DIR_W){ //move east if snake direction is not east
        interuptMask = 0;
        move_snake(snake_dir());

      }
      if(((SWITCHES & 0x55) == DIR_W) && snake_dir() != DIR_E){ //*move west if snake direction is not east
        interuptMask = 0;
        snake_move(snake_dir());
      }
      if((SWITCHES & 0x55) == DIR_S && snake_dir() != DIR_N){ //move south if snake direction is not north
        interuptMask = 0;
        snake_move(snake_dir());
      }
      if((SWITCHES & 0x55) == DIR_N && snake_dir() != DIR_S){ //move north if snake direction is not south
        interuptMask = 0;
        snake_move(snake_dir());
      }
      else{
        (snake_move(snake_dir()))  
      }
      collision_apple();
      
      } 

  
    
}

}

extern void enable_interrupt(); // för att kunna användas ghär från boot.s
/* Add your code here for initializing interrupts. */
void labinit(void)
{

    interuptMask = 85; //tilllåter intrupt från 01010101 dvs sw6 = N, sw4 = S, sw2 = W, sw0 = E
    
    *periodL = (2999999) &0xFFFF;
    *periodH = (2999999 >> 16); // 30MHz 0.1 100ms

    // Starta timern: start=1, CONT=1, ITO=1
    *timerControl = (1<<2) | (1<<1) | (1<<0); // sätter controll bitar till ett 
    
    //cont- behöver ej starta manuellt , ito- så avbrott när noll och får signal om det, start- startar timer
    enable_interrupt(); // från boot.S
}