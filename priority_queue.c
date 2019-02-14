/* Priority Queue
/* by:       _  __  
       )\/) / ` ) ) 
      (  ( (_. /_/   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include "priority_queue.h"
#include "vector.h"

//Functions Implementations -----------------
//Problem Solving Functions -----------------
void Init_Priority_Queue(PQ *pq, int length){
	pq->state = malloc(sizeof(State) * length)
	pq->first = -1;
	pq->last = -1;
	pq->length = length;
}

void Ajust_Going_Up(PQ *pq, int index){
	State aux;

	int parent = index / 2;

	while((index - pq->first) > 0){
		if(pq->state[index] > pq->state[parent])
			break;

		aux = pq->state[index];
		pq->state[index] = pq->state[parent];
		pq->state[parent] = aux;

		index = parent;
		parent = index / 2;
	}
}

void Adjust_Going_Down(PQ *pq, int index){
	State aux;

	int current = index;
	int left = current * 2 + 1;
	int right = current * 2 + 2;

	while(true){
		if(left <= pq->last)
			if(pq->state[left].key < pq->state[current].key){
				aux = pq->state[left].key;
				pq->state[current].key = pq->state[left].key;
				pq->state[left].key = aux;
				current = left;
			}

		else if(right <= pq->last)
			if(pq->state[right].key < pq->state[current].key){
				aux = pq->state[right].key;
				pq->state[current].key = pq->state[right].key;
				pq->state[right].key = aux;
				current = right;
			}

		else
			break;

		left = current * 2 + 1;
	    right = current * 2 + 2;
	}
}

void Insert(PQ *pq, State s){
	if(pq == NULL)
		return;

	if(pq->last == pq->length - 1)
		return;

	pq->state[pq->last + 1] = s;
	pq->last++;

	Ajust_Going_Up(pq, pq->last);
}

State *Remove(PQ *pq){
	if(pq == NULL)
		return NULL;

	if(pq->last < 0)
		return NULL;

	State *bye = (State *) malloc(sizeof(State));
	*bye = pq->state[0];

	if(pq->last != 0){
		pq->state[0] = pq->state[pq->last];
		(pq->last)--;
		Adjust_Going_Down(pq, 0);
	}

	else
		(pq->last)--;

	return bye;
}

int Priority_Queue_Size(PQ pq){
	return pq.last + 1;
}

void Delete_Priority_Queue(PQ *pq){
	if(pq == NULL)
		return;

	int count;

	for(count = 0 ; count < pq->length ; count++)
		free(pq->state[count].set);

	free(pq->state);
	pq->last = pq->length = 0;

	free(pq);
}

//Printing Functions ------------------------
int Print_Priority_Queue(PQ pq){
	int index;

	printf("Priority Queue\n");
	printf("---------------------\n");

	for(index = 0 ; index <= info.last_position ; index++){
		printf("key: %d\n", pq.state[index].key);
		Print_Matrix(pq.state[index].set, M);
	}

	printf("---------------------\n");

	return 0;
}

//-------------------------------------------