#include "Agent.h"
#include "state.h"
#include "environment.h"
#include <iostream>
using namespace std;


Agent::Agent(state pos):agent_pos(pos.xs, pos.ys, pos.xb, pos.yb), parent(0)
{
}


Agent::~Agent(void)
{
}


bool Agent::goal_test(state final, state node)
{
	if(node.xb == final.xb && node.yb == final.yb)
		return true;

	return false;
}


state *Agent::check_around(Agent *p, state current, environment *E)
{
	int xs = current.xs;
	int ys = current.ys;
	int xb = current.xb;
	int yb = current.yb;

	E->updatePage(p->getstate());

	if((E->A[xs][ys] == '.' || E->A[xs][ys] == 'X'))
	{
		state *cstate = new state(xs, ys, xb, yb);
		return cstate;
	}

	if(E->A[xs][ys] == '#')
		return 0;

	if(E->A[xs][ys] == '@' && p->childflag == 'l' && (E->A[xs][ys-1] == '.' || E->A[xs][ys-1] == 'X'))
	{
		state *cstate = new state(xs, ys, xb, yb - 1);
		return cstate;
	}

	if(E->A[xs][ys] == '@' && p->childflag == 'l' && E->A[xs][ys-1] == '#')
		return 0;

	if(E->A[xs][ys] == '@' && p->childflag == 'r' && (E->A[xs][ys+1] == '.' || E->A[xs][ys+1] == 'X'))
	{
		state *cstate = new state(xs, ys, xb, yb + 1);
		return cstate;
	}

	if(E->A[xs][ys] == '@' && p->childflag == 'r' && E->A[xs][ys+1] == '#')
		return 0;

	if(E->A[xs][ys] == '@' && p->childflag == 'u' && (E->A[xs-1][ys] == '.' || E->A[xs-1][ys] == 'X'))
	{
		state *cstate = new state(xs, ys, xb - 1, yb);
		return cstate;
	}

	if(E->A[xs][ys] == '@' && p->childflag == 'u' && E->A[xs-1][ys] == '#')
		return 0;

	if(E->A[xs][ys] == '@' && p->childflag == 'd' && (E->A[xs+1][ys] == '.' || E->A[xs+1][ys] == 'X'))
	{
		state *cstate = new state(xs,ys,xb+1,yb);
		return cstate;
	}

	if(E->A[xs][ys] == '@' && p->childflag == 'd' && E->A[xs+1][ys] == '#')
		return 0;
}


state Agent::getstate()
{
	return  agent_pos;
}


bool Agent::operator < (Agent &current)
{
	return this->h <= current.h;
}