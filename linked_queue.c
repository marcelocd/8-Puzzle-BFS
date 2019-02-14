/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"
#include "vector.h"

//Functions Implementations -----------------
//Problem Solving Functions -----------------
Node *New_Node(State s){
	Node *new_node = (Node *) malloc(sizeof(Node));

	if(new_node != NULL){
		new_node->state = s;
		new_node->next = NULL;
	}
	
	return new_node;
}

void Enqueue(Node **first, Node **last, Node *node){
	if(*first == NULL)
		*first = *last = node;

	else{
		(*last)->next = node;
		*last = node;
	}
}

Node *Dequeue(Node **first, Node**last){
	 if(*first == NULL)
	 	return NULL;

	Node *bye = *first;
	*first = (*first)->next;

	if(*first == NULL)
		*last = NULL;

	return bye;
}

int Queue_Size(Node *first){
	Node *aux = first;
	int size = 0;

	while(aux != NULL){
		size++;
		aux = aux->next;
	}

	return size;
}

void Clear_Node(Node *node){
	if(node == NULL)
		return;

	node->state.key = 0;
	Clear_Vector(node->state.set, M);
	node->next = NULL;
}

void Free_Node(Node **node){
	if(*node != NULL){
		Clear_Node(*node);
		free((*node)->state.set);
		free(*node);
		*node = NULL;
	}
}

int Delete_Queue(Node **first, Node **last){
	if(*first == NULL)
		return -1;

	Node *bye;

	while(*first != NULL){
		bye = *first;
		*first = (*first)->next;

		free(bye->state.set);
		Free_Node(&bye);
	}

	*last = NULL;

	return 0;
}

//Printing Functions ------------------------
int Print_Queue(Node *first){
	if(first == NULL)
		return -1;

	Node *aux = first;

	printf("---------------------\n");

	while(aux != NULL){
		printf("key: %d\n", aux->state.key);
		printf("cost: %d\n", aux->state.cost);
		Print_Matrix(aux->state.set, 3, 3);

		aux = aux->next;
	}

	printf("---------------------\n");

	return 0;
}

//-------------------------------------------