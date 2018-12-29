#include "state.h"

#pragma once
class environment
{
public:
	environment(void);
	~environment(void);
	void find_positions(state *P);
	void updatePage(state *P);
	void show();
	void getfile();
	
public:
	char A[100][100];
	char B[100][100];
	int r,c,pf;
	

};