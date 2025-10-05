#ifndef HARDWARE_H
#define HARDWARE_H  
// Definiera basadresser för hårdvarukomponenter
#define TIMER_STATUS   (*(volatile int*)(0x04000020))  // pekare till status register
#define interuptMask    (*(volatile int*)(0x04000012))  // pekare till swtich 
#define edgeCapture     (*(volatile int*)(0x040000013))
#define SWITCHES (*(volatile int*)0x04000010) // pekare till switcharna 


// Timerregister
#define PERIODL_ADDR      0x04000028
#define PERIODH_ADDR      0x0400002C
#define TIMERCONTROL_ADDR 0x04000024

static volatile int* periodL      = (volatile int*) PERIODL_ADDR;      // pekare till låga del av period register
static volatile int* periodH      = (volatile int*) PERIODH_ADDR;      // pekare till höga del av period register
static volatile int* timerControl = (volatile int*) TIMERCONTROL_ADDR; // pekare till kontroll-timer





#endif 