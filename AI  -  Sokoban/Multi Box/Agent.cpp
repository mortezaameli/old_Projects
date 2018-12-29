#include "Agent.h"
#include "state.h"
#include "environment.h"
#include <iostream>
#include <string.h>
using namespace std;


Agent::Agent():parent(0)
{
	
}


Agent::~Agent(void)
{
}


bool Agent::goal_test(state final[10],char B[100][100],int c)
{
	
	for(int k= 0; k < c; k++)
		if(B[final[k].xb][final[k].yb] != '1')
			return false;
		return true;

}


bool Agent::check_around(Agent *p,state current,state currentp[10],environment *E)
{
	int xs = current.xs;
	int ys = current.ys;

	E->updatePage(p->agent_pos);
	if((E->A[xs][ys] == '.' || E->A[xs][ys] == 'X')){
		for(int k= 0; k <E->pf; k++){
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = p->agent_pos[k].xb;
			currentp[k].yb = p->agent_pos[k].yb;	
	}
		return true;
}
	
	if( E->A[xs][ys] == '#')
		return false;

	if(E->A[xs][ys] == '@' && p->childflag == 'l' && (E->A[xs][ys-1] =='.' || E->A[xs][ys-1] =='X') ){
		for(int k= 0; k <E->pf; k++){
			if(p->agent_pos[k].xb == xs && p->agent_pos[k].yb == ys ){
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = xs;
			currentp[k].yb = ys-1;
			}
			else{
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = p->agent_pos[k].xb;
			currentp[k].yb = p->agent_pos[k].yb;
			}
		}
		return true;
	}
	if(E->A[xs][ys] == '@' && p->childflag == 'l' && (E->A[xs][ys-1] =='#' || E->A[xs][ys-1] =='@'))
		return false;

	if(E->A[xs][ys] == '@' && p->childflag == 'r' && (E->A[xs][ys+1] =='.' || E->A[xs][ys+1] =='X')){
		for(int k= 0; k <E->pf; k++){
			if(p->agent_pos[k].xb == xs && p->agent_pos[k].yb == ys){
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = xs;
			currentp[k].yb = ys+1;
			}
			else{
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = p->agent_pos[k].xb;
			currentp[k].yb = p->agent_pos[k].yb;
			}
		}
		return true;
	}
	if(E->A[xs][ys] == '@' && p->childflag == 'r' && (E->A[xs][ys+1] =='#' || E->A[xs][ys+1] =='@'))
		return false;

	if(E->A[xs][ys] == '@' && p->childflag == 'u' && (E->A[xs-1][ys] =='.' || E->A[xs-1][ys] =='X')){
		for(int k= 0; k <E->pf; k++){
			if(p->agent_pos[k].xb == xs && p->agent_pos[k].yb == ys){
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = xs-1;
			currentp[k].yb = ys;
			}
			else
			{
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = p->agent_pos[k].xb;
			currentp[k].yb = p->agent_pos[k].yb;
			}
		}
		return true;
	}
	if(E->A[xs][ys] == '@' && p->childflag == 'u' && (E->A[xs-1][ys] =='#' || E->A[xs-1][ys] =='@'))
		return false;

	if(E->A[xs][ys] == '@' && p->childflag == 'd' && (E->A[xs+1][ys] =='.' || E->A[xs+1][ys] =='X')){
		for(int k= 0; k <E->pf; k++){
			if(p->agent_pos[k].xb == xs && p->agent_pos[k].yb == ys){
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = xs+1;
			currentp[k].yb = ys;
			}
			else{
			currentp[k].xs = xs;
			currentp[k].ys = ys;
			currentp[k].xb = p->agent_pos[k].xb;
			currentp[k].yb = p->agent_pos[k].yb;
			}
		}
		return true;
	}
	if(E->A[xs][ys] == '@' && p->childflag == 'd' && (E->A[xs+1][ys] =='#' || E->A[xs+1][ys] =='@'))
		return false;
	
}
	

bool Agent::operator < (Agent &current)
{
	return this->h <= current.h;
}

void Agent::setstate(state *A,int c)
{
	for(int i = 0; i < c; i++)
		agent_pos[i] = A[i];

}

void Agent::setchild(char s)
{
	checkchild = s;
}