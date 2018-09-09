/*
* include a header file
* do something unique
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

//STATE NAME
#define moveEast 2
#define moveNorth 0
#define moveSouth 1
#define moveWest 3
#define nas 4
#define NAS "ZOOOOOM"

#define Forward 0
#define Back 1
#define Left 2
#define Right 3

//What to Do in the State
#define hello "The World is Yours"
#define North "Moved North"
#define South "Moved South"
#define West "Moved West"
#define East "Moved East"

//state your in
#define FN "Facing North"
#define FS "Facing South"
#define FE "Facing East"
#define FW "Facing West"

//State Structure
struct State{
  const char* a;
  const char* w;
  const char* s;
  const char* d;
  const char* q;
  unsigned int next[5];
};
typedef struct State stateholder;

stateholder FSM[5] ={
                 //a,    w,    s,    d,   q     //NEXT STATE[F,B,L,R,SPECIAL]
  /*facingNorth:0*/{West, North, South, East, NAS,  {moveNorth, moveSouth, moveWest, moveEast, nas}},
  /*facingSouth:1*/{East, South, North, West, NAS,  {moveSouth, moveNorth, moveEast, moveWest, nas}},
  /*facingEast:2*/{North, East, West, South, NAS,  {moveEast, moveWest, moveNorth, moveSouth, nas}},
  /*facingWest:3*/{South, West, East, North, NAS,  {moveWest, moveEast, moveSouth, moveNorth, nas}},
  /*SecretLevel:4*/{East, hello, North, South, NAS,  {moveNorth, moveSouth, moveEast, moveWest, moveNorth}}
};


int main(int argc, char* argv[]){
  unsigned char userinput;
  unsigned int S = 0;
  int input;

  while(1){
    printf("Please enter a state a,w,s,d:\n");
    scanf(" %c",&userinput);

    switch(userinput){
      case 'a':
        printf("State:%d:%s\n", S, FSM[S].a);
        input = Left;
        break;
      case 'w':
        printf("State:%d:%s\n", S, FSM[S].w);
        input = Forward;
        break;
      case 's':
        printf("State:%d:%s\n", S, FSM[S].s);
        input = Back;
        break;
      case 'd':
        printf("State:%d:%s\n", S, FSM[S].d);
        input = Right;
        break;
      case 'q':
        printf("State:%d:%s\n", S, FSM[S].q);
        input = FSM[S].next[4];
        break;
    }
    S = FSM[S].next[input];

  }

}
