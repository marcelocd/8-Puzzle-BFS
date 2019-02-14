/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search.h"
#include "8puzzle.h"
#include "vector.h"
#include "linked_queue.h"
#include "hash.h"

//Functions Implementations -----------------
//Problem Solving Functions -----------------
bool Is_Solvable(State s, State goal_state){
	int i, j, k;
	int goal_state_index;
	int inversions = 0;

	for(i = 0 ; i < SIZE ; i++){
		if(i != s.k0){
			for(j = 0 ; j < SIZE ; j++)
				if(s.set[i] == goal_state.set[j]){
					goal_state_index = j;
					break;
				}

			for(j = (i + 1) ; j < SIZE ; j++)
				if(j != s.k0)
					for(k = 0 ;  k < goal_state_index ; k++)
						if(k != goal_state.k0)
							if(goal_state.set[k] == s.set[j]){
								inversions++;
								break;
							}
		}
	}

	if(inversions % 2 == 0)
		return true;

	return false;
}

bool States_Are_Equal(State s1, State s2){
	int k;

	for(k = 0 ; k < SIZE ; k++)
		if(s1.set[k] != s2.set[k])
			return false;

	return true;
}

bool State_Already_Visited(State s, Hash_Table h){
	Node *aux = h[s.key].first;

	while(aux != NULL){
		if(States_Are_Equal(aux->state, s))
			return true;

		aux = aux->next;
	}

	return false;
}

void Transfer_State(State *s1, State *s2){
	s2->key = s1->key;
	Transfer_Vector(s1->set, s2->set, SIZE);
	s2->k0 = s1->k0;
	s2->cost = s1->cost;
}

bool Is_Solution(State s, State goal_state){
	if(s.key == goal_state.key){
		int k;

		for(k = 0 ; k < SIZE ; k++)
			if(s.set[k] != goal_state.set[k])
				return false;

		return true;
	}

	return false;
}

State *Solution(State *solution_state){
	State *solution = (State *) malloc(sizeof(State) * (solution_state->cost + 1));
	State *aux = solution_state;
	State s;

	int cost = solution_state->cost;
	int index;

	for(index = 0 ; index <= cost ; index++){
		s.set = New_Vector(SIZE);
		solution[index] = s;
		Transfer_State(aux, &(solution[index]));
		aux = aux->parent;
	}

	return solution;
}

void Free_Solution(State **solution){
	State *aux = *solution;

	if(*solution == NULL)
		return;

	int index;
	int cost = aux[0].cost;

	for(index = cost ; index >= 0 ; index --)
		free(aux[index].set);

	free(aux);
	*solution = NULL;
}

//Search Functions --------------------------
State *BFS(State initial_state, State goal_state, Hash_Table opened, Hash_Table closed){
	if(!Is_Solvable(initial_state, goal_state))
		return NULL;

	if(Is_Solution(initial_state, goal_state))
		return Solution(&initial_state);

	State *current = New_State(initial_state.set, initial_state.k0, initial_state.cost, initial_state.parent);
	State *successor;
	State s[4];
	Node *new_node = New_Node(*current);
	int position[MAX_STATES];
	int current_index = 0;
	int last_index = 0;
	int k0;
	int i;

	for(i = 0 ; i < 4 ; i++)
		s[i].set = New_Vector(SIZE);

	for(i = 0 ; i < MAX_STATES ; i++)
		position[i] = -1;

	Enqueue(&(opened[current->key].first), &(opened[current->key].last), new_node);
	position[last_index] = current->key;

	while(current != NULL){
		k0 = current->k0;

		/* MOVE UP */ 
		if(k0 - M >= 0){
			Transfer_State(current, &s[0]);
			Move_Up(&s[0]);

			if(!State_Already_Visited(s[0], closed) && !State_Already_Visited(s[0], opened)){
				successor = New_State(s[0].set, s[0].k0, s[0].cost + 1, current);
				
				if(Is_Solution(*successor, goal_state)){
					for(i = 0 ; i < 4 ; i++)
						free(s[i].set);

					return Solution(successor);
				}

				new_node = New_Node(*successor);
				Enqueue(&(opened[successor->key].first), &(opened[successor->key].last), new_node);
				last_index++;
				position[last_index] = successor->key;
			}
		}
			
		/* MOVE DOWN */			
		if(k0 + M < SIZE){
			Transfer_State(current, &s[1]);
			Move_Down(&s[1]);

			if(!State_Already_Visited(s[1], closed) && !State_Already_Visited(s[1], opened)){
				successor = New_State(s[1].set, s[1].k0, s[1].cost + 1, current);

				if(Is_Solution(*successor, goal_state)){
					for(i = 0 ; i < 4 ; i++)
						free(s[i].set);

					return Solution(successor);
				}

				new_node = New_Node(*successor);
				Enqueue(&(opened[successor->key].first), &(opened[successor->key].last), new_node);
				last_index++;
				position[last_index] = successor->key;
			}
		}

		/* MOVE RIGHT */ 
		if(k0 % N + 1 < N){
			Transfer_State(current, &s[2]);
			Move_Right(&s[2]);

			if(!State_Already_Visited(s[2], closed) && !State_Already_Visited(s[2], opened)){
				successor = New_State(s[2].set, s[2].k0, s[2].cost + 1, current);
				
				if(Is_Solution(*successor, goal_state)){
					for(i = 0 ; i < 4 ; i++)
						free(s[i].set);

					return Solution(successor);
				}

				new_node = New_Node(*successor);
				Enqueue(&(opened[successor->key].first), &(opened[successor->key].last), new_node);
				last_index++;
				position[last_index] = successor->key;
			}
		}		

		/* MOVE LEFT */
		if(k0 % N - 1 >= 0){
			Transfer_State(current, &s[3]);
			Move_Left(&s[3]);

			if(!State_Already_Visited(s[3], closed) && !State_Already_Visited(s[3], opened)){
				successor = New_State(s[3].set, s[3].k0, s[3].cost + 1, current);
				
				if(Is_Solution(*successor, goal_state)){
					for(i = 0 ; i < 4 ; i++)
						free(s[i].set);

					return Solution(successor);
				}

				new_node = New_Node(*successor);
				Enqueue(&(opened[successor->key].first), &(opened[successor->key].last), new_node);
				last_index++;
				position[last_index] = successor->key;
			}
		}

		new_node = Dequeue(&(opened[current->key].first), &(opened[current->key].last));
		new_node->next = NULL;
		Enqueue(&(closed[current->key].first), &(closed[current->key].last), new_node);

		current = NULL;

		if(current_index++ < MAX_STATES)
			if(position[current_index] != -1)
				current = &(opened[position[current_index]].first->state);
	}

	return NULL;
}

//-------------------------------------------

/*

bool Is_Solvable(State s, State goal_state){
	int i, j;
	int inversions = 0;

	for(i = 0 ; i < SIZE ; i++)
		if(i != s.k0)
			for(j = (i + 1) ; j < SIZE ; j++)
				if(j != s.k0)
					if(s.set[i] > s.set[j])
						inversions++;

	if((goal_state.k0 / N) % 2 != 0 && inversions % 2 != 0)
		return true;

	if((goal_state.k0 / N) % 2 == 0 && inversions % 2 == 0)
		return true;

	return false;
}

*/