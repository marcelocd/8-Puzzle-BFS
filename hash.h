/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

#define   A            400135675
#define   B            551284587
#define   C            334466698
#define   D            199874534
#define   E            111457792
#define   F            766521303
#define   G            988745444
#define   H            133467095
#define   I            677721349
#define   J            26666912345
#define   PRIME        32920473601
#define   MAX_STATES   181440

//Problem Models ----------------------------
typedef   Queue *  Hash_Table;

//-------------------------------------------

//Functions Prototypes ----------------------
//Initializing Functions --------------------
Hash_Table New_Hash_Table(int);

//Problem Solving Functions -----------------
int Hash(short *);
int Hash_Table_Size(Hash_Table, int);
void Delete_Hash_Table(Hash_Table *, int);

//Printing Functions ------------------------
void Print_Hash_Table(Hash_Table);

//-------------------------------------------

#endif