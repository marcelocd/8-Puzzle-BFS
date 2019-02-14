/* UFG - Instituto de Informática               *
 * Inteligência Artificial: Trabalho 1          *
 * Alunos: Marcelo Cardoso Dias      201305842  *
 *         Giovanna Aguiar de Castro 201501563  */

#ifndef _8PUZZLE_H_
#define _8PUZZLE_H_

#define   M              3
#define   N              3
#define   SIZE         M * N
#define   MAX_STATES   181440

//Problem Models ----------------------------
typedef struct st{
	int key;     /* Hash */
	short *set;  /* Game Matrix */
	int k0;
	int cost;
	struct st *parent; 
}State;

//------------------------------------------- 

//Functions Prototypes ----------------------
//Initializing Functions --------------------
State *New_State(short *, int, int, State *);
void Initial_State1(State *);
void Initial_State2(State *);
void Initial_State3(State *);
void Goal_State1(State *);
void Goal_State2(State *);
void Goal_State3(State *);

//Rules Functions ---------------------------
void Move_Up(State *s);
void Move_Down(State *s);
void Move_Right(State *s);
void Move_Left(State *s);

//Problem Solving Functions -----------------
void Free_State(State *);

//-------------------------------------------

#endif