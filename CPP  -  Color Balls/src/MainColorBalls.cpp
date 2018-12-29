#include "graphics.h"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

class partition{
public:
	int Y;

	partition(){
		Y=90;
	}
	static void draw_wall(){
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		line(40,40,600,40);
		line(40,440,600,440);
		line(320,40,320,90);
		line(320,440,320,140);
		setcolor(9);
		rectangle(35,40,40,440);
		setfillpattern(p,9);
		floodfill(36,41,9);
		setcolor(12);
		rectangle(600,40,605,440);
		setfillpattern(p,12);
		floodfill(601,41,12);
	}
	void divider_down(){
				//PAEEN ZADE SHOD
		if(Y<385)
			Y+=25;
		setcolor(0);
		line(320,40,320,440);
		setcolor(11);
		line(320,40,320,Y);
		line(320,440,320,Y+50);
	}
	void divider_up(){
				//BALA ZADE SHOD
		if(Y>40)
			Y-=25;
		setcolor(0);
		line(320,40,320,440);
		setcolor(11);
		line(320,40,320,Y);
		line(320,440,320,Y+50);
	}
	void decision(){
		int dec=5;
		char ch1,ch2;
		ch1=getch();
		if(ch1==-32)
			ch2=getch();
		//bala 
		if(ch1==-32 && ch2== 72)
			dec=2;
		//paeen
		if(ch1==-32 && ch2== 80)
			dec=1;
		switch (dec){
		case 2:
			divider_up();
			break;
		case 1:
			divider_down();
			break;
		}
	}
};

class ball{
public:
	int compute;
	int xc,yc,radius;
	int ax,ay;
	int color;
	int dx,dy;

	ball(){
		compute=0;
		xc=yc=0;
		ax=1;
		ay=1;	
		color=0;
		radius=5;
		dx=(rand()%10+1);
		dy=(rand()%10+1);
	}
	int guess_direction(){
		int g=rand()%2;
		return g;
	}
	void toop(int ball_color){
		setcolor(ball_color);
		circle(xc,yc,radius);
	}
	void rough(){
		while(!(((xc>60 && xc<300) || (xc>340 && xc<540)) && (yc>60 && yc<420))){
			xc = rand()%520 + 60;
			yc = rand()%360 + 60;
		}
	}
	void move(){ 
		toop(0);
		xc+=ax*dx;
		yc+=ay*dy;
		toop(color);
	}
};	

class game{
public:
	int n;
	ball b[16];
	partition p;
	int blue_ok,red_ok;

	game(int _n){
	n=_n;
	blue_ok=red_ok=0;
	}
	void find_direction(){
		for(int k=0; k<n ;k++){
			b[k].rough();
			int gra1,gra2;
			gra1 = b[k].guess_direction();
			gra2 = b[k].guess_direction();
			if(gra1 == 1)
				b[k].ax=1 ;
			if(gra1 == 0)
				b[k].ax=-1 ;
			if(gra2 == 1)
				b[k].ay=1 ;
			if(gra2 == 0)
				b[k].ay=-1 ;
		}
	}
	bool reflex(int k){
		//divare rast
		if(b[k].xc>=594-b[k].dx && b[k].xc<=594 && b[k].ax==1 && b[k].ay==-1){	b[k].ax=-1;	return true;}
		if(b[k].xc>=594-b[k].dx && b[k].xc<=594 && b[k].ax==1 && b[k].ay==1){	b[k].ax=-1;	return true;}
		//divare chap
		if(b[k].xc>=46 && b[k].xc<=46+b[k].dx && b[k].ax==-1 && b[k].ay==-1){	b[k].ax=1;	return true;}	
		if(b[k].xc>=46 && b[k].xc<=46+b[k].dx && b[k].ax==-1 && b[k].ay==1) {	b[k].ax=1;	return true;}
		//divare bala
		if(b[k].yc>=46 && b[k].yc<=46+b[k].dy && b[k].ax==1 && b[k].ay==-1){		b[k].ay=1;	return true;}
		if(b[k].yc>=46 && b[k].yc<=46+b[k].dy && b[k].ax==-1 && b[k].ay==-1){	 b[k].ay=1;	return true;}
		//divare paeien
		if(b[k].yc>=434-b[k].dy && b[k].yc<=434 && b[k].ax==1 && b[k].ay==1){	b[k].ay=-1;	return true;}
		if(b[k].yc>=434-b[k].dy && b[k].yc<=434 && b[k].ax==-1 && b[k].ay==1){	b[k].ay=-1;	return true;}
		//residan be dariche tighe
		if( ((b[k].xc>=315-b[k].dx && b[k].xc<=315) || (b[k].xc>=326 && b[k].xc<=326+b[k].dx)) && b[k].yc>=p.Y && b[k].yc<=p.Y+50 && b[k].color==9){
			if(b[k].compute==1){
				blue_ok--;
				b[k].compute=0;
			}
			return false;
		}
		if( ((b[k].xc>=315-b[k].dx && b[k].xc<=315) || (b[k].xc>=326 && b[k].xc<=326+b[k].dx)) && b[k].yc>=p.Y && b[k].yc<=p.Y+50 && b[k].color==12){
			if(b[k].compute==1){
			red_ok--;
			b[k].compute=0;
			}
			return false;
		}
		//tighe chap
		if(b[k].xc>=315-b[k].dx && b[k].xc<=315 && b[k].ax==1 && b[k].ay==-1){	b[k].ax=-1;	return true;}
		if(b[k].xc>=315-b[k].dx && b[k].xc<=315 && b[k].ax==1 && b[k].ay==1){	b[k].ax=-1;	return true;}
		//tighe rast
		if(b[k].xc>=326 && b[k].xc<=326+b[k].dx && b[k].ax==-1 && b[k].ay==-1){b[k].ax=1;	return true;}
		if(b[k].xc>=326 && b[k].xc<=326+b[k].dx && b[k].ax==-1 && b[k].ay==1){	b[k].ax=1;	return true;}
		
		return false;
	}
	void find_color(){
		for(int k=0;k<n;k++){
			if(k%2 == 0)
				b[k].color=9;
			if(k%2 != 0)
				b[k].color=12;
		}
	}
	void process_game(){
		int win=0;
		while(1 && win!=1){
			if(blue_ok==n/2 && red_ok==n/2){
				setcolor(11);
				line(320,40,320,440);
				break;
			}
			if(kbhit() && p.Y>=40 && p.Y<=435)
				p.decision();
			for(int k=0; k<n; k++){
				if(b[k].xc>=40 && b[k].xc<=315 && b[k].color==9 && b[k].compute==0){
					blue_ok++;
					b[k].compute=1;
				}
				if(b[k].xc>=326 && b[k].xc<=600 && b[k].color==12 && b[k].compute==0){
					red_ok++;
					b[k].compute=1;
				}
				if(reflex(k)==true)	
					continue;
				b[k].move(); 
			}
		}
	}
};

int main(){
	int a;
	do{
	cout << "Enter the ball count:";
	cin >> a;
	}while(a%2 != 0);
	system("cls");
	game g(a);
	g.find_direction();
	g.find_color();
	cout << "Press any key..." ;
	getch();
	system("cls");
	int seconds1 = time (NULL);
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"");
    partition :: draw_wall();	
	g.process_game();
	int seconds2 = time (NULL);
	cout << "\t\t\t*YOU WIN*" << endl << endl;
	cout << "\t\t\tPASSED TIME:" << seconds2-seconds1;
	getch();
	closegraph();
	return 0;
}