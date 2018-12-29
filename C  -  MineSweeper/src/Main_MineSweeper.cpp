#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>
#include<iostream>
using namespace std;
#define randomize()(srand(time(0)))
#define random(x)(rand()%x)
int m,n;
struct bomb{
     int visible;
     char p;
     int tb;
     };
//***********************************
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X=x;
	dwCursorPosition.Y=y;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}
//***************************
int tbomb(int a,int row,int column){
int t,s;
t=row*column;
if(a==1)	s=0.1*t;
if(a==2)	s=0.2*t;
if(a==3)	s=0.3*t;
return s;
}
//***************************
void init(struct bomb **x){
int i,j;
for(i=0;i<m;i++)
	for(j=0;j<n;j++){
		x[i][j].visible=0;
		x[i][j].p='\0';
		x[i][j].tb=0;
		}
}
//***************************
void draw(struct bomb **x){
int i,j;
for(i=1;i<=m;i++){
   gotoxy(1,5+3*(i-1));
   printf("%d",i);
   }//end of for(i=1)
for(j=1;j<=n;j++){
   if(j>=10){
     gotoxy(3+3*(j-1),1);
     printf(" %d",j);
     continue;
     }
   gotoxy(4+3*(j-1),1);
   printf(" %d",j);
   }//end of for(j=1)
for(i=0;i<m;i++){
   for(j=0;j<n;j++){
      gotoxy(5+3*j,5+3*i);
      if(x[i][j].visible==1){
	if(x[i][j].p=='G')
	  printf("%c|",x[i][j].p);
	if(x[i][j].p=='\0'){
	  if(x[i][j].tb==0)
	    printf(" |");
	  if(x[i][j].tb!=0)
	    printf("%d|",x[i][j].tb);
	  }//end of if
	}//end of if
      if(x[i][j].visible==0)
	     printf("*|");
      }//end of for(j)
   printf("\n\n");
   }//end of for(i)
}
//***************************
void guess(struct bomb **x ,int tm){
int i,g,q;
randomize();
for(i=1;i<=tm;i++){
	g=random(m);
	q=random(n);
	if(x[g][q].p!='M')
		x[g][q].p='M';
	else{
		i--;
		continue;
		}
	}
}
//***************************
void amount(struct bomb **x){
int i,j,a,b;
for(i=0;i<m;i++)
   for(j=0;j<n;j++){
      if(x[i][j].p=='\0')
	continue;
      if(x[i][j].p=='M')
	for(a=i-1;a<=i+1;a++)
	   for(b=j-1;b<=j+1;b++)
	      if(a>=0 && a<m && b>=0 && b<n)
		if(x[a][b].p=='\0')
		  x[a][b].tb++;
      }//end of for(j)
}
//***************************
void khonsa(int i,int j,struct bomb **x){
int k,l,r,s,hide;
for(k=i-1;k<=i+1;k++)
   for(l=j-1;l<=j+1;l++)
      if(k>=0 && k<m && l>=0 && l<n){
	hide=0;
	for(r=k-1;r<=k+1;r++)
	   for(s=l-1;s<=l+1;s++)
	      if(r>=0 && r<m && s>=0 && s<n)
		if(x[r][s].visible==0)
		  hide++;
	if(hide==0)
	  x[k][l].tb=0;
	}//end of if
}
//***************************
void back(int i,int j,struct bomb **x){
int k,l;
x[i][j].visible=1;
for(k=i-1;k<=i+1;k++)
   for(l=j-1;l<=j+1;l++)
      if(k>=0 && k<m && l>=0 && l<n){
	if(x[k][l].visible==1){
	  khonsa(k,l,x);
	  continue;
	  }
	if(x[k][l].tb!=0 && x[k][l].p=='\0'){
	  x[k][l].visible=1;
	  khonsa(k,l,x);
	  }
	if(x[k][l].tb==0 && x[k][l].p=='\0'){
	  khonsa(k,l,x);
	  back(k,l,x);
	  }
	}
}
//***************************
void search(struct bomb **x,int tm){
int f=0,i,j,a,b,k,l;
char ch;
draw(x);
while(f==0 && tm!=0){
     printf("\n\t\t\tBOMB CURRENT:%d\n",tm);
     printf("\n\nEnter row and column and state position(e/m):");
     scanf("%d%d%c",&i,&j,&ch);
     a=i-1;	b=j-1;
     if(x[a][b].p=='\0' && x[a][b].tb==0 && x[a][b].visible==0 && ch=='e'){
       back(a,b,x);
       khonsa(a,b,x);
       }
     if(x[a][b].p=='\0' && x[a][b].tb!=0 && x[a][b].visible==0 && ch=='e'){
       x[a][b].visible=1;
       khonsa(a,b,x);
       }
     if(x[a][b].p=='M' && ch=='m'){
       tm--;
       x[a][b].visible=1;
       x[a][b].p='G';
       khonsa(a,b,x);
       }
     if(x[a][b].p=='M' && ch=='e')
	    f=1;
     system("cls");
     draw(x);
     }//end of while
if(f==1)
  printf("\n\t\t\t*YOU LOSE*");
if(tm==0){
  printf("\n\t\t\t*YOU WIN*");
   }
}
//***************************
int main()
{
		int level,k;
	int i=0,j=0;
	printf("please enter horizontal (n):");
	scanf("%d",&n);
	printf("please enter Vertical (m):");
	scanf("%d",&m);
	//struct bomb x[m][n];
	bomb **x;
	x=new bomb*[m];
	for(i=0;i<m;i++)
		x[i]=new bomb[n];
	system("cls");
	printf("level game:\n   1.easy\n   2.medium\n   3.hard");
	printf("\n enter number 1 or 2 or 3:\n");
	scanf("%d",&level);
	system("cls");
	k=tbomb(level,m,n);//tedade minha
	init(x);
	guess(x,k);
	amount(x);
	search(x,k);
	//**********************************************************************
	// show clock:
	/*while(!kbhit())	{
		if(i<60){
			gotoxy(n/2,0);
			i++;
			printf("%d:%d",j,i);
			Sleep(100);
			gotoxy(n/2,0);}
		if(i>=60){
			j++;
			i=0;
			printf("%d:%d",j,i);}
		gotoxy(n/2,0);}*/
	//end of clock***********************************************************
	getch();
	return 0;
}
