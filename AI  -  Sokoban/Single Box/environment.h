#include "state.h"

#pragma once
class environment
{
public:

	environment(void);
	~environment(void);

	state final_position();

	state find_positions();

	void updatePage(state);

	void show();

	void getfile();
	

public:

	char A[100][100];
	char B[100][100];

	int r, c;
};