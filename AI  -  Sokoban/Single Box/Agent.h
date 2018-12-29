#include "state.h"
#include "environment.h"
#include <vector>

#pragma once
class Agent
{
public:
	Agent(state);
	~Agent(void);

	bool goal_test(state ,state);

	bool operator < (Agent &);

    state *check_around(Agent *,state ,environment *);

	state getstate();


public:
	float h;
	char childflag;
	state agent_pos;

	Agent *parent;
	Agent *lChild;
	Agent *rChild;
	Agent *uChild;
	Agent *dChild;
};