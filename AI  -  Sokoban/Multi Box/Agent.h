#include "state.h"
#include "environment.h"
#include <vector>
#include <string.h>

#pragma once
class Agent
{
public:
	Agent();
	~Agent(void);
	bool goal_test(state p[10],char B[100][100],int );
	bool operator <(Agent &);
    bool check_around(Agent *p,state ,state current[10] ,environment * );
	void setstate(state *A,int );
	void setchild(char);

public:
	float h;
	char checkchild;
	char childflag;
	state agent_pos[10];
	Agent *parent;
	Agent *lChild;
	Agent *rChild;
	Agent *uChild;
	Agent *dChild;

};