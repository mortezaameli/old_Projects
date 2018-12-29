#include "environment.h"
#include "state.h"
#include <conio.h>
#include <iostream>
using namespace std;


environment::environment(void):pf(0)
{
	this->getfile();
}


environment::~environment(void)
{
}


void environment::getfile()
{
	freopen("input.txt","r",stdin);

	cin >> r >> c;
	for(int i = 0 ; i<r ; i++)
		for(int j = 0 ; j<c ; j++)
			cin >> A[i][j];

	for(int i = 0 ; i<r ; i++)
		for(int j = 0 ; j<c ; j++){
			if(A[i][j] == 'X'){
				B[i][j] ='1';
				pf++;
			}
			else
				B[i][j] = '0';
		}
}


void environment::show()
{
	
	for(int i = 0 ; i<r ; i++){
		for(int j = 0 ; j<c ; j++)
			cout << A[i][j];
	cout << endl;
	}
 }


void environment::find_positions(state p[10])
{
	
	
		for(int i = 0 ; i<r ; i++)
			for(int j = 0 ; j<c ; j++){
				if(A[i][j] == 'S'){
					for(int k= 0; k <pf; k++){
						p[k].xs = i;
						p[k].ys = j;
					}
					break;
				}
			}
	
	for(int k= 0; k <pf; k++)
		for(int i = 0 ; i<r ; i++)
			for(int j = 0 ; j<c ; j++){
				if(A[i][j] == '@'){
					p[k].xb = i;
					p[k].yb = j;
					k++;
					continue;
				}
			}
}


void environment::updatePage(state q[10])
{

	for(int i = 0 ; i<r ; i++){
		for(int j = 0 ; j<c ; j++){
			if(A[i][j] == '.' || A[i][j] == 'S' || A[i][j] == '@' )
				A[i][j] = '.';
			if(A[i][j] == '#')
				A[i][j] = '#';
			if(A[i][j] == 'X')
				A[i][j] = 'X';
		}
	}
	for(int k= 0; k <pf; k++){
		A[q[k].xs][q[k].ys] = 'S';
		A[q[k].xb][q[k].yb] = '@';
	}

	/*environment::show();*/

	
}
