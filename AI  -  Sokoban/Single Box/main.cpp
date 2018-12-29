#include "environment.h"
#include "state.h"
#include "Agent.h"
#include <iostream>
#include <conio.h>
#include <queue>
#include <Windows.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Search{
public:
	Search():Parent(0), t(0), v(0), w(0){}

	void SequenceActivity(Agent *);

	void stringActivity(state ,state);

	void bfs();

	void dfs();

	void heuristic1();

	void number_of_pushing(state ,state);

	bool nodeArray(state *);

	float f(state ,state);

public:
	environment E;

	Agent *Parent;

	vector <Agent *> node;

	string SA;

	int t;
	int v;
	int w;
};


int main()
{
	cout << endl << "---------------BFS Algorithm----------------" << endl;
	Search *b = new Search();
	b->bfs();

	cout << endl << endl << "---------------DFS Algorithm----------------" << endl; 
	Search *d = new Search();
	d->dfs();

	cout << endl << endl << "---------------HEURISTIC Algorithm----------------" << endl;
	Search *h = new Search(); 
	h->heuristic1();
	cout << endl;

	getch();
	return 0;
}


void Search::bfs()
{
	queue <Agent *> Q;
	state pstate = E.find_positions();
	Parent = new Agent(pstate);
	state cstate = pstate;
	Q.push(Parent);
	E.show();
	state goal = E.final_position();
	cout << endl;
	node.push_back(Parent);

	while(true)
	{
		if(Q.empty())
		{
			cout << "The question is not answered!!" << endl;
			cout << "V:" << v << endl;
			break;
		}

		Agent *p = Q.front();
		bool goalTest = p->goal_test(goal, p->getstate());

		if(goalTest == true)
		{
			E.updatePage(p->getstate());
			E.show();
			cout << endl;
			Search::SequenceActivity(p);
			cout << endl << "T:" << t <<endl;
			cout << "V:" << v << endl ;
			cout << "W:" << w;
			break;
		}

		else
		{
			pstate = p->getstate();

			Q.pop();
			int xs = p->agent_pos.xs;
			int ys = p->agent_pos.ys;
			int xb = p->agent_pos.xb;
			int yb = p->agent_pos.yb;

			p->childflag = 'u';
			state u(xs-1, ys, xb, yb);
			state *cstate = p->check_around(p, u, &E);
			bool checku = Search::nodeArray(cstate);
			if(checku)
			{
				v ++;
				E.updatePage(*cstate);
				p->uChild = new Agent(*cstate);
				p->uChild->parent = p;
				Q.push(p->uChild);
				node.push_back(p->uChild);
			}

			p->childflag = 'd';
			state d(xs+1, ys, xb, yb);
		    cstate = p->check_around(p, d, &E);
			bool checkd = Search::nodeArray(cstate);
			if(checkd)
			{
				v ++;
				E.updatePage(*cstate);
                p->dChild = new Agent(*cstate);
				p->dChild->parent = p;
				Q.push(p->dChild);
				node.push_back(p->dChild);
			}

			p->childflag = 'l';
			state l(xs, ys-1, xb, yb);
		    cstate = p->check_around(p, l, &E);
			bool checkl = Search::nodeArray(cstate);
			if(checkl)
			{
				v ++;
				E.updatePage(*cstate);
				p->lChild = new Agent(*cstate);
				p->lChild->parent = p;
				Q.push(p->lChild);
				node.push_back(p->lChild);
			}

			p->childflag = 'r';
			state r(xs, ys+1, xb, yb);
		    cstate = p->check_around(p, r, &E);
			bool checkr = Search::nodeArray(cstate);
			if(checkr){
				v ++;
				E.updatePage(*cstate);
				p->rChild = new Agent(*cstate);
				p->rChild->parent = p;
				Q.push(p->rChild);
				node.push_back(p->rChild);
			}
		}
	}
}


void Search::dfs()
{
	stack <Agent *> S;
	state pstate = E.find_positions();
	Parent = new Agent(pstate);
	state cstate = pstate;
	S.push(Parent);
	E.show();
	state goal = E.final_position();
	cout << endl;
	node.push_back(Parent);

	while(true)
	{
		if(S.empty())
		{
			cout << "The question is not answered!!" <<endl;
			cout << "V:" << v << endl;
			cout << "W:" << w;
			break;
		}

		Agent *p = S.top();
		bool goalTest = p->goal_test(goal, p->getstate());
		if(goalTest == true)
		{
			E.updatePage(p->getstate());
			E.show();
			cout << endl;
			Search::SequenceActivity(p);
			cout << endl <<"T:" << t <<endl;
			cout << "V:" << v <<endl;
			cout << "W:" << w;
			break;
		}

		else
		{
			pstate = p->getstate();
			
			S.pop();
			int xs = p->agent_pos.xs;
			int ys = p->agent_pos.ys;
			int xb = p->agent_pos.xb;
			int yb = p->agent_pos.yb;

			p->childflag = 'u';
			state u(xs-1, ys, xb, yb);
			state *cstate = p->check_around(p, u, &E);
			bool checku = Search::nodeArray(cstate);
			if(checku)
			{
				v ++;
				E.updatePage(*cstate);
				p->uChild = new Agent(*cstate);
				p->uChild->parent = p;
				S.push(p->uChild);
				node.push_back(p->uChild);
			}

			p->childflag = 'd';
			state d(xs+1, ys, xb, yb);
		    cstate = p->check_around(p, d, &E);
			bool checkd = Search::nodeArray(cstate);
			if(checkd)
			{
				v ++;
				E.updatePage(*cstate);
                p->dChild = new Agent(*cstate);
				p->dChild->parent = p;
				S.push(p->dChild);
				node.push_back(p->dChild);
			}

			p->childflag = 'l';
			state l(xs, ys-1, xb, yb);
		    cstate = p->check_around(p, l, &E);
			bool checkl = Search::nodeArray(cstate);
			if(checkl)
			{
				v ++;
				E.updatePage(*cstate);
				p->lChild = new Agent(*cstate);
				p->lChild->parent = p;
				S.push(p->lChild);
				node.push_back(p->lChild);
			}

			p->childflag = 'r';
			state r(xs, ys+1, xb, yb);
		    cstate = p->check_around(p, r, &E);
			bool checkr = Search::nodeArray(cstate);
			if(checkr)
			{
				v ++;
				E.updatePage(*cstate);
				p->rChild = new Agent(*cstate);
				p->rChild->parent = p;
				S.push(p->rChild);
				node.push_back(p->rChild);
			}
		}
	}
}


void Search::heuristic1()
{
	priority_queue <Agent *> PQ;
	state pstate = E.find_positions();
	Parent = new Agent(pstate);
	state cstate = pstate;
	PQ.push(Parent);
	E.show();
	state goal = E.final_position();
	cout << endl;
	node.push_back(Parent);
	Parent->h = Search::f(goal, pstate);

	while(true)
	{
		if(PQ.empty())
		{
			cout << "The question is not answered!!" << endl;
			cout << "V:" << v << endl;
			cout << "W:" << w;
			break;
		}

		Agent *p = PQ.top();
		bool goalTest = p->goal_test(goal, p->getstate());
		if(goalTest == true)
		{
			E.updatePage(p->getstate());
			E.show();
			cout << endl;
			Search::SequenceActivity(p);
			cout << endl << "T:" << t <<endl;
			cout << "V:" << v << endl;
			cout << "W:" << w;
			break;
		}

		else
		{
			pstate = p->getstate();
			
			PQ.pop();
			int xs = p->agent_pos.xs;
			int ys = p->agent_pos.ys;
			int xb = p->agent_pos.xb;
			int yb = p->agent_pos.yb;

			p->childflag = 'u';
			state u(xs-1, ys, xb, yb);
			state *cstate = p->check_around(p, u, &E);
			bool checku = Search::nodeArray(cstate);
			if(checku)
			{
				v ++;
				E.updatePage(*cstate);
				p->uChild = new Agent(*cstate);
				p->uChild->h  = Search::f(goal,*cstate);
				p->uChild->parent = p;
				PQ.push(p->uChild);
				node.push_back(p->uChild);
			}

			p->childflag = 'd';
			state d(xs+1, ys, xb, yb);
		    cstate = p->check_around(p, d, &E);
			bool checkd = Search::nodeArray(cstate);
			if(checkd)
			{
				v ++;
				E.updatePage(*cstate);
                p->dChild = new Agent(*cstate);
				p->dChild->h = Search::f(goal,*cstate);
				p->dChild->parent = p;
				PQ.push(p->dChild);
				node.push_back(p->dChild);
			}

			p->childflag = 'l';
			state l(xs, ys-1, xb, yb);
		    cstate = p->check_around(p, l, &E);
			bool checkl = Search::nodeArray(cstate);
			if(checkl)
			{
				v ++;
				E.updatePage(*cstate);
				p->lChild = new Agent(*cstate);
				p->lChild->h = Search::f(goal,*cstate);
				p->lChild->parent = p;
				PQ.push(p->lChild);
				node.push_back(p->lChild);
			}

			p->childflag = 'r';
			state r(xs, ys+1, xb, yb);
		    cstate = p->check_around(p, r, &E);
			bool checkr = Search::nodeArray(cstate);
			if(checkr)
			{
				v ++;
				E.updatePage(*cstate);
				p->rChild = new Agent(*cstate);
				p->rChild->h = Search::f(goal,*cstate);
				p->rChild->parent = p;
				PQ.push(p->rChild);
				node.push_back(p->rChild);
			}
		}
	}
}


void Search::SequenceActivity(Agent *finalChild)
{
	Agent *currentNode = finalChild;
	Agent *parent = finalChild->parent;
	cout << "Sequence of Activity: ";

	while(parent)
	{
		t ++;
		Search::number_of_pushing(parent->getstate(), currentNode->getstate());
		Search::stringActivity(parent->getstate(), currentNode->getstate());
		currentNode = currentNode->parent;
		parent = currentNode->parent;
	}

	string::iterator it1 = SA.begin();
	string::iterator it2 = SA.end();
	reverse(it1, it2);

	cout << SA << endl;
}


void Search::stringActivity(state p,state c)
{
	if(p.xs == c.xs+1 || p.xb == c.xb+1)
		SA += "U";
	if(p.xs == c.xs-1 || p.xb == c.xb-1)
		SA += "D";
	if(p.ys == c.ys-1 || p.yb == c.yb-1)
		SA += "R";
	if(p.ys == c.ys+1 || p.yb == c.yb+1)
		SA += "L";
}


bool Search::nodeArray(state *current)
{
	if(current == 0)
		return false;
	for(int i = 0; i < node.size(); i ++)
		if((node[i]->getstate().xs == current->xs) && (node[i]->getstate().ys == current->ys) && (node[i]->getstate().xb == current->xb) &&(node[i]->getstate().yb == current->yb) )
			return false;
	return true;
}


void Search::number_of_pushing(state p, state c)
{
	if(p.xb+1 == c.xb && p.yb == c.yb )
		w++;
	if(p.xb-1 == c.xb && p.yb == c.yb )
		w++;
	if(p.xb == c.xb && p.yb+1 == c.yb )
		w++;
	if(p.xb == c.xb && p.yb-1 == c.yb )
		w++;
}


float Search::f(state final, state node)
{
	float i_StoB = node.xb - node.xs;
	float j_StoB = node.yb - node.ys;

	float lenght_StoB = sqrt(pow(i_StoB,2) + pow(j_StoB,2));

	float i_BtoF = final.xb - node.xb;
	float j_BtoF = final.yb - node.yb;

	float lenght_BtoF = sqrt(pow(i_BtoF,2) + pow(j_BtoF,2));
	float l = lenght_BtoF + lenght_StoB;

	return l;
}