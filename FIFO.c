
/*
* FIFO.c
* include a header file
* First In First Out Queue implementation in C
* C program
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FIFO.h"

/*Global Variables*/
#define FIFO_SIZE 100
#define SUCCESS 0
#define FAIL -1


int FIFO[FIFO_SIZE];
int *pointerpush;
int *pointerpop;
int currentSize;



int pushnew(int item){
  if(pointerpush == pointerpop && currentSize > 0){
    //we ran out of space
    return FAIL;
  }
  else{
    *pointerpush = item;
    currentSize = currentSize + 1;
    pointerpush = &FIFO[(currentSize)%FIFO_SIZE];
  }


  return SUCCESS;
}

int popnew(){
  int result;
  if (currentSize > 0 ){

    result = *pointerpop;
    currentSize = (currentSize - 1) % FIFO_SIZE;
    pointerpop = (pointerpop +1);
    if(pointerpop == (&FIFO[FIFO_SIZE]) ){
      pointerpop = &FIFO[0];
    }
  }
  return result;
}

int initnew(){
  pointerpush = &FIFO[0];
  pointerpop = &FIFO[0];
  currentSize = 0;
  return SUCCESS;

}

int main(int argc, char* argv[]){
  int ret;
  initnew();
  for(int i = 0; i < 103; i +=1 ){
    ret = pushnew(i);
    if(ret == SUCCESS){
      printf("SUCCESS on Push\n");
    }
    else{
      printf("FAIL on Push\n");
    }

  }

    for(int j = 0; j < 101; j +=1){
      printf("pop value: %d\n", popnew());
    }

    for (int k = 0; k < 10; k +=1){
      ret = pushnew(k);
      if(ret == SUCCESS){
        printf("SUCCESS on Push\n");
      }
      else{
        printf("FAIL on Push\n");
      }
    }

    for(int z = 0; z < 10; z +=1){
      printf("pop value: %d\n", popnew());
    }
    printf("End of Main test program for FIFO");


}
