#include "environment.h"
#include "state.h"
#include <conio.h>
#include <iostream>
using namespace std;


environment::environment(void)
{
	this->getfile();
}


environment::~environment(void)
{
}


void environment::getfile()
{
	freopen("input.txt", "r",stdin);

	cin >> r >> c;
	for(int i = 0 ; i < r; i ++)
		for(int j = 0; j < c; j ++)
			cin >> A[i][j];

	/*for(int i = 0; i < r; i ++)
		for(int j = 0; j < c; j ++)
		{
			if(A[i][j] == 'X' || A[i][j] == '.' || A[i][j] == 'S' || A[i][j] == '@')
				B[i][j] = '0';
			if(A[i][j] == '#')
				B[i][j] = 'b';
		}*/
}


void environment::show()
{
	for(int i = 0; i < r; i ++)
	{
		for(int j = 0; j < c; j ++)
			cout << A[i][j];
		cout << endl;
	}
 }


state environment::find_positions()
{
	int x1, y1, x2, y2;

	for(int i = 0; i < r; i ++)
		for(int j = 0; j < c; j ++)
		{
			if(A[i][j] == 'S')
			{
				x1 = i;
				y1 = j;
			}
			if(A[i][j] == '@')
			{
				x2 = i;
				y2 = j;
			}
		}

	return state(x1, y1, x2, y2);
}


void environment::updatePage(state New)
{
	
	int xn1, yn1, xn2, yn2;

	xn1 = New.xs;
	yn1 = New.ys;
	xn2 = New.xb;
	yn2 = New.yb;

	for(int i = 0; i < r; i ++)
	{
		for(int j = 0; j < c; j ++)
		{
			if(A[i][j] == '.' || A[i][j] == 'S' || A[i][j] == '@')
				A[i][j] = '.';
		}
	}

	A[xn1][yn1] = 'S';
	A[xn2][yn2] = '@';
}


state environment::final_position()
{
	int x1=0, y1=0, x2, y2;
	for(int i = 0; i < r; i ++)
		for(int j = 0; j < c; j ++)
			if(A[i][j] == 'X')
			{
				x2 = i;
				y2 = j;
			}

	return state(x1, y1, x2, y2);
}