/* Priority Queue
/* by:       _  __  
       )\/) / ` ) ) 
      (  ( (_. /_/   */

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include "8puzzle.h"

//Problem Models ----------------------------
typedef struct{
	State *state;
	int last;
	bool is_empty;
	bool is_full;
	int length;
}PQ;

//-------------------------------------------

//Functions Prototypes ----------------------
//Problem Solving Functions -----------------
void Init_Priority_Queue(PQ *, int);
void Ajust_Going_Up(PQ *, int);
void Adjust_Going_Down(PQ *, int);
void Insert(PQ *, State);
State *Remove(PQ *);
int Priority_Queue_Size(PQ);
void Delete_Priority_Queue(PQ *);

//Printing Functions ------------------------
int Print_Priority_Queue(PQ);

//-------------------------------------------
#endif
