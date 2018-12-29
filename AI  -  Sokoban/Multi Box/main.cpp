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
	Search( ):Parent(0),t(0),v(0),w(0){}
	void SequenceActivity(Agent * );
	void stringActivity(Agent *);
	void bfs();
	void dfs();
	bool nodeArray(state c[]);
	float f(state ,state );
	

public:
	environment E;
	Agent *Parent;
	vector <Agent *> node;
	int t;
	int v;
	int w;
};

int main()
{
	cout << endl;
	cout << "---------------BFS Algorithm----------------" << endl;
	Search *b = new Search();
	b->bfs();
	cout << endl << endl;
	cout << "---------------DFS Algorithm----------------" << endl; 
	Search *d = new Search();
	d->dfs();
	cout << endl << endl;
	getch();
	return 0;
}


void Search::bfs()
{
	queue <Agent *> Q;
	state pstate[10];
	E.find_positions(pstate);
	Parent = new Agent();
	Parent->setstate(pstate,E.pf);
	Parent->setchild('P');
	E.show();
	Q.push(Parent);
	cout << endl;
	node.push_back(Parent);
	state arraystate[10];
	while(1)
	{
		if(Q.empty()){
			E.updatePage(arraystate);
			cout << "The question is not answered!!" << endl;
			cout << "V:" << v ;
			E.show();
			break;
		}
		Agent *p = Q.front();
		bool goalTest = p->goal_test(p->agent_pos,E.B,E.pf);
		if(goalTest == true){
			E.updatePage(p->agent_pos);
			E.show();
			cout << endl;
			Search::SequenceActivity(p);
			cout << endl << "T:" << t <<endl;
			cout << "V:" << v << endl ;
			break;
		}
		else{
			
			
			Q.pop();
			int xs = p->agent_pos[0].xs;
			int ys = p->agent_pos[0].ys;
			int xb = p->agent_pos[0].xb;
			int yb = p->agent_pos[0].yb;

			p->childflag = 'u';
			state u;
			u.setState(xs-1,ys,xb,yb);
			bool checku;
			state arraystate[10];
			bool uc = p->check_around(p,u,arraystate,&E);
			if (uc)
			    checku = Search::nodeArray(arraystate);
			else
				checku = false;
			if(checku){
				v++;
				E.updatePage(arraystate);
				p->uChild = new Agent();
				p->uChild->setstate(arraystate,E.pf);
				p->uChild->setchild('U');
				p->uChild->parent = p;
				Q.push(p->uChild);
				node.push_back(p->uChild);
			}
			p->childflag = 'd';
			state d;
			d.setState(xs+1,ys,xb,yb);
			bool checkd;
			bool dc = p->check_around(p,d,arraystate,&E);
			if (dc)
			    checkd = Search::nodeArray(arraystate);
			else
				checkd = false;
			if(checkd){
				v++;
				E.updatePage(arraystate);
                p->dChild = new Agent();
				p->dChild->parent = p;
				p->dChild->setstate(arraystate,E.pf);
				p->dChild->setchild('D');
				Q.push(p->dChild);
				node.push_back(p->dChild);
			}
			p->childflag = 'l';
			state l;
			l.setState(xs,ys-1,xb,yb);
			bool checkl;
			bool lc = p->check_around(p,l,arraystate,&E);
			if (lc)
			    checkl = Search::nodeArray(arraystate);
			else
				checkl = false;
			if(checkl){
				v++;
				E.updatePage(arraystate);
				p->lChild = new Agent();
				p->lChild->parent = p;
				p->lChild->setstate(arraystate,E.pf);
				p->lChild->setchild('L');
				Q.push(p->lChild);
				node.push_back(p->lChild);
			}
			p->childflag = 'r';
			state r;
			r.setState(xs,ys+1,xb,yb);
			bool checkr;
			bool rc = p->check_around(p,r,arraystate,&E);
			if (rc)
			    checkr = Search::nodeArray(arraystate);
			else
				checkr = false;
			if(checkr){
				v++;
				E.updatePage(arraystate);
				p->rChild = new Agent();
				p->rChild->setstate(arraystate,E.pf);
				p->rChild->setchild('R');
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
	state pstate[10];
	E.find_positions(pstate);
	Parent = new Agent();
	Parent->setstate(pstate,E.pf);
	Parent->setchild('P');
	E.show();
	S.push(Parent);
	cout << endl;
	node.push_back(Parent);
	state arraystate[10];
	while(1)
	{
		if(S.empty()){
			E.updatePage(arraystate);
			cout << "The question is not answered!!" << endl;
			cout << "V:" << v ;
			E.show();
			break;
		}
		Agent *p = S.top();
		bool goalTest = p->goal_test(p->agent_pos,E.B,E.pf);
		if(goalTest == true){
			E.updatePage(p->agent_pos);
			E.show();
			cout << endl;
			Search::SequenceActivity(p);
			cout << endl << "T:" << t <<endl;
			cout << "V:" << v << endl ;
			break;
		}
		else{
			
			
			S.pop();
			int xs = p->agent_pos[0].xs;
			int ys = p->agent_pos[0].ys;
			int xb = p->agent_pos[0].xb;
			int yb = p->agent_pos[0].yb;

			p->childflag = 'u';
			state u;
			u.setState(xs-1,ys,xb,yb);
			bool checku;
			state arraystate[10];
			bool uc = p->check_around(p,u,arraystate,&E);
			if (uc)
			    checku = Search::nodeArray(arraystate);
			else
				checku = false;
			if(checku){
				v++;
				E.updatePage(arraystate);
				p->uChild = new Agent();
				p->uChild->setstate(arraystate,E.pf);
				p->uChild->setchild('U');
				p->uChild->parent = p;
				S.push(p->uChild);
				node.push_back(p->uChild);
			}
			p->childflag = 'd';
			state d;
			d.setState(xs+1,ys,xb,yb);
			bool checkd;
			bool dc = p->check_around(p,d,arraystate,&E);
			if (dc)
			    checkd = Search::nodeArray(arraystate);
			else
				checkd = false;
			if(checkd){
				v++;
				E.updatePage(arraystate);
                p->dChild = new Agent();
				p->dChild->parent = p;
				p->dChild->setstate(arraystate,E.pf);
				p->dChild->setchild('D');
				S.push(p->dChild);
				node.push_back(p->dChild);
			}
			p->childflag = 'l';
			state l;
			l.setState(xs,ys-1,xb,yb);
			bool checkl;
			bool lc = p->check_around(p,l,arraystate,&E);
			if (lc)
			    checkl = Search::nodeArray(arraystate);
			else
				checkl = false;
			if(checkl){
				v++;
				E.updatePage(arraystate);
				p->lChild = new Agent();
				p->lChild->parent = p;
				p->lChild->setstate(arraystate,E.pf);
				p->lChild->setchild('L');
				S.push(p->lChild);
				node.push_back(p->lChild);
			}
			p->childflag = 'r';
			state r;
			r.setState(xs,ys+1,xb,yb);
			bool checkr;
			bool rc = p->check_around(p,r,arraystate,&E);
			if (rc)
			    checkr = Search::nodeArray(arraystate);
			else
				checkr = false;
			if(checkr){
				v++;
				E.updatePage(arraystate);
				p->rChild = new Agent();
				p->rChild->setstate(arraystate,E.pf);
				p->rChild->setchild('R');
				p->rChild->parent = p;
				S.push(p->rChild);
				node.push_back(p->rChild);
			}
		}
	}
}

void Search::SequenceActivity(Agent *finalChild)
{
	Agent *currentNode = finalChild;
	Agent *parent = finalChild->parent;
	cout << "Sequence of Activity: " ;
	while(parent){
		t++;
		Search::stringActivity(currentNode);
		currentNode = currentNode->parent;
		parent = currentNode->parent;
	}
}

void Search::stringActivity(Agent *c)
{
	cout << c->checkchild;
	
}

bool Search::nodeArray(state q[10])
{
	int fc = 0;
	for(int i = 0; i<node.size(); i++ ){
		for(int j = 0; j<E.pf; j++){
			if((node[i]->agent_pos[j].xs == q[j].xs) && (node[i]->agent_pos[j].ys == q[j].ys) && (node[i]->agent_pos[j].xb == q[j].xb) &&(node[i]->agent_pos[j].yb == q[j].yb) )
				fc++;
				if(fc == E.pf)
					return false;
		}
		fc = 0;
		}
	return true;
}
