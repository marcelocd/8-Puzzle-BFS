/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "8puzzle.h"
#include "hash.h"
#include "linked_queue.h"

//Functions Prototypes ----------------------
//Problem Solving Functions -----------------
bool State_Already_Visited(State, Hash_Table);
bool Is_Solution(State, State);
State *Solution(State *);
void Free_Solution(State **);

//Search Functions --------------------------
State *BFS(State , State, Hash_Table, Hash_Table);

//-------------------------------------------

#endif