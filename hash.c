/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "linked_queue.h"

//Functions Implementation ------------------
//Initializing Functions --------------------
Hash_Table New_Hash_Table(int length){
	Hash_Table new_hash_table = (Hash_Table) malloc(sizeof(Queue) * length);

	Queue aux;
	int i;

	for(i = 0 ; i < length ; i ++){
		new_hash_table[i] = aux;
		new_hash_table[i].first = new_hash_table[i].last = NULL;
	}

	return new_hash_table;
}

//Problem Solving Functions -----------------
int Hash(short *set){
	unsigned long long int key = 0;

	key += ((unsigned long long int)(set[0])) * A;
	key += ((unsigned long long int)(set[1])) * B;
	key += ((unsigned long long int)(set[2])) * C;
	key += ((unsigned long long int)(set[3])) * D;
	key += ((unsigned long long int)(set[4])) * E;
	key += ((unsigned long long int)(set[5])) * F;
	key += ((unsigned long long int)(set[6])) * G;
	key += ((unsigned long long int)(set[7])) * H;
	key += ((unsigned long long int)(set[8])) * I;

	return ((int)(((key + J) % PRIME) % MAX_STATES));
}

int Hash_Table_Size(Hash_Table h, int length){
	int i;
	int size = 0;

	for(i = 0 ; i < length ; i++)
		if(h[i].first != NULL)
			size += Queue_Size(h[i].first);

	return size;
}

void Delete_Hash_Table(Hash_Table *h, int length){
	int i;

	for(i = 0 ; i < length ; i++)
		if((*h)[i].first != NULL)
			Delete_Queue(&((*h)[i].first), &((*h)[i].last));

	free(*h);
	*h = NULL;
}

//Printing Functions ------------------------
void Print_Hash_Table(Hash_Table h){
	int i;

	for(i = 0 ; i < MAX_STATES ; i++)
		if(h[i].first != NULL)
			Print_Queue(h[i].first);
}

//-------------------------------------------