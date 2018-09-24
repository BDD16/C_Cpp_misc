/*
*
* Finite State machine using function pointers
* C program
* In this case it is a finite state machine where shows you direction
* and movement i.e. moved north, means now your facing north, so buttons change
* awsd keyboard a(left), w(forward), s(back), d(right).  Begin facing North
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include "State.h"

//STATE NAME
#define moveEast 2
#define moveNorth 0
#define moveSouth 1
#define moveWest 3
#define nas 4

#define Forward 0
#define Back 1
#define Left 2
#define Right 3

//state your in
#define FN "Facing North"
#define FS "Facing South"
#define FE "Facing East"
#define FW "Facing West"

//*------Foward Declarations-------
void West(void);
void East(void);
void South(void);
void North(void);
void NAS(void);


//State Structure with function pointers
struct State{
  void (*a)(void);
  void (*w)(void);
  void (*s)(void);
  void (*d)(void);
  void (*q)(void);
  unsigned int next[5];
};
typedef struct State stateholder;

stateholder FSM[5] ={
                 //a,    w,    s,    d,   q     //NEXT STATE[F,B,L,R,SPECIAL]
  /*facingNorth:0*/{&West, &North, &South, &East, &NAS,  {moveNorth, moveSouth, moveWest, moveEast, nas}},
  /*facingSouth:1*/{&East, &South, &North, &West, &NAS,  {moveSouth, moveNorth, moveEast, moveWest, nas}},
  /*facingEast:2*/{&North, &East, &West, &South, &NAS,  {moveEast, moveWest, moveNorth, moveSouth, nas}},
  /*facingWest:3*/{&South, &West, &East, &North, &NAS,  {moveWest, moveEast, moveSouth, moveNorth, nas}},
  /*SecretLevel:4*/{&East, &West, &North, &South, &NAS,  {moveNorth, moveSouth, moveEast, moveWest, moveNorth}}
};
//*-----------------------------
//*Just a function that prints Move North
//*-----------------------------
void North(void){
  printf("Moved North\n");
  return;
}
//*-----------------------------
//*Just a function that prints Move North
//*-----------------------------
void South(void){
  printf("Moved South\n");
  return;
}
//*-----------------------------
//*Just a function that prints Moved North
//*-----------------------------
void East(void){
  printf("Moved East\n");
  return;
}
//*-----------------------------
//*Just a function that prints Moved West
//*-----------------------------
void West(void){
  printf("Moved West\n");
  return;
}
//*-----------------------------
//*Just a function that prints special secret sauce
//*-----------------------------
void NAS(void){
  printf("special secret sauce\n");
  return;
}

int main(int argc, char* argv[]){
  unsigned char userinput;
  unsigned int S = 0;
  int input;

  while(1){
    printf("Please enter a state a,w,s,d:\n");
    scanf(" %c",&userinput);

    switch(userinput){
      case 'a':
        FSM[S].a();
        input = Left;
        break;
      case 'w':
        FSM[S].w();
        input = Forward;
        break;
      case 's':
        FSM[S].s();
        input = Back;
        break;
      case 'd':
        FSM[S].d();
        input = Right;
        break;
      case 'q':
        FSM[S].q();
        input = FSM[S].next[4];
        break;
    }
    S = FSM[S].next[input];

  }

}
