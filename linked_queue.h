/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#include "8puzzle.h"

//Problem Models ----------------------------
typedef struct node{
	State state;
	struct node *next;
}Node;

typedef struct{
	Node *first;
	Node *last;
}Queue;

//-------------------------------------------

//Functions Prototypes ----------------------
//Problem Solving Functions -----------------
Node *New_Node(State);
void Enqueue(Node **, Node **, Node *);
Node *Dequeue(Node **, Node **);
int Queue_Size(Node *);
int Delete_Queue(Node **, Node **);

//Printing Functions ------------------------
int Print_Queue(Node *);

//-------------------------------------------

#endif