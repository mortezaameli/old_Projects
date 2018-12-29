#include "graphics.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;
void print_in_graphic_page(int x , int y , char []);

class shape
{
protected:
	int x , y;
	string name;
public:
	virtual void show() = 0 
	{
		setcolor(15);
		rectangle(x-20 , y-20 , x+20 , y+20);
	}
	string getname(){	return name;	}
};
class carrot : public shape
{
public:
	carrot(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "CARROT";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		int k = 14;
		setcolor(k);
		line(x , y-15 , x-6 , y+6);
		line(x , y-15 , x+6 , y+6);
		line(x-6 , y+6 , x+6 , y+6);
		setfillpattern(p , k);
		floodfill(x , y , k);

		setcolor(10);
		line(x , y+6 , x-5 , y+15);
		line(x , y+6 , x+5 , y+15);
		line(x-5 , y+15 , x+5 , y+15);
		setfillpattern(p , 10);
		floodfill(x , y+12 , 10);

		shape::show();
	}	 
};
class grass : public shape
{
public:
	grass(int ix , int iy) 
	{
		x = ix;
		y = iy;
		name = "GRASS";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(2);
		setfillpattern(p , 2);
		rectangle(x-20 , y-20 , x+20 , y+20);
		floodfill(x , y , 2);

		shape::show();
	}
};
class space : public shape
{
public:
	space(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "SPACE";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		shape::show();
	}
};
class bobby : public shape
{
public:
	bobby(int ix , int iy)
	{	
		x = ix;
		y = iy;
		name = "BOBBY";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		shape::show();
	}
};
class inactive_trap : public shape
{
public:
	inactive_trap(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "INACTIVE TRAP";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(7);
		setfillpattern(p , 7);
		rectangle(x-20 , y-20 , x+20 , y+20);
		floodfill(x , y , 7);

		shape::show();
	}
};
class active_trap : public shape
{
public:
	active_trap(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "ACTIVE TRAP";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(8);
		setfillpattern(p , 8);
		rectangle(x-20 , y-20 , x+20 , y+20);
		floodfill(x , y , 8);

		setcolor(12);
		line(x-10 , y-10 , x+10 , y+10);
		line(x+10 , y-10 , x-10 , y+10);

		shape::show();
	}
};
class vertical_passage : public shape
{
public:
	vertical_passage(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "VERTICAL PASSAGE";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		setfillpattern(p , 0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(12);
		setfillpattern(p , 12);
		rectangle(x-20 , y-20 , x-12 , y+20);
		floodfill(x-18 , y , 12);
		rectangle(x+12 , y-20 , x+20 , y+20);
		floodfill(x+18 , y , 12);

		shape::show();
	}
};
class horizontal_passage : public shape
{
public:
	horizontal_passage(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "HORIZONTAL PASSAGE";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(12);
		setfillpattern(p , 12);
		rectangle(x-20 , y-20 , x+20 , y-12);
		floodfill(x , y-18 , 12);
		rectangle(x-20 , y+12 , x+20 , y+20);
		floodfill(x , y+18 , 12);

		shape::show();
	}
};
class right_direction : public shape
{
public:
	right_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "RIGHT DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		line(x-15 , y-20 , x+10 , y);
		line(x-15 , y+20 , x+10 , y);
		line(x-10 , y-20 , x+15 , y);
		line(x-10 , y+20 , x+15 , y);
		line(x-15 , y-20 , x-10 , y-20);
		line(x-15 , y+20 , x-10 , y+20);
		setfillpattern(p , 14);
		floodfill(x+12 , y , 14);

		shape::show();
	}
};
class left_direction : public shape
{
public:
	left_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "LEFT DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		line(x+10 , y-20 , x-15 , y);
		line(x+10 , y+20 , x-15 , y);
		line(x+15 , y-20 , x-10 , y);
		line(x+15 , y+20 , x-10 , y);
		line(x+10 , y-20 , x+15 , y-20);
		line(x+10 , y+20 , x+15 , y+20);

		setfillpattern(p , 14);
		floodfill(x-12 , y , 14);

		shape::show();
	}
};
class up_direction : public shape
{
public:
	up_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "UP DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		line(x-20 , y+10 , x , y-15);
		line(x-20 , y+15 , x , y-10);
		line(x+20 , y+10 , x , y-15);
		line(x+20 , y+15 , x , y-10);
		line(x-20 , y+10 , x-20 , y+15);
		line(x+20 , y+10 , x+20 , y+15);

		setfillpattern(p , 14);
		floodfill(x , y-12 , 14);

		shape::show();
	}
};
class down_direction : public shape
{
public:
	down_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "DOWN DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(11);
		circle(x , y , 15);
		setfillpattern(p , 11);
		floodfill(x , y , 11);

		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		line(x-20 , y-10 , x , y+15);
		line(x-20 , y-15 , x , y+10);
		line(x+20 , y-10 , x , y+15);
		line(x+20 , y-15 , x , y+10);
		line(x-20 , y-10 , x-20 , y-15);
		line(x+20 , y-10 , x+20 , y-15);

		setfillpattern(p , 14);
		floodfill(x , y+12 , 14);

		shape::show();
	}
};
class not_pressed_switch_button_passage : public shape
{
public:
	not_pressed_switch_button_passage(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "NOT PRESSED SWITCH BUTTON PASSAGE";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(13);
		circle(x , y-4 , 10);
		setfillpattern(p , 13);
		floodfill(x , y-4 , 13);
		circle(x , y+4 , 10);

		shape::show();
	}
};
class pressed_switch_button_passage : public shape
{
public:
	pressed_switch_button_passage(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "PRESSED SWITCH BUTTON PASSAGE";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(13);
		circle(x , y-1 , 10);
		setfillpattern(p , 13);
		floodfill(x , y-1 , 13);
		circle(x , y+2 , 10);

		shape::show();
	}
};
class not_pressed_switch_button_direction : public shape
{
public:
	not_pressed_switch_button_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "NOT PRESSED SWITCH BUTTON DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		circle(x , y-4 , 10);
		setfillpattern(p , 14);
		floodfill(x , y-4 , 14);
		circle(x , y+4 , 10);

		shape::show();
	}
};
class pressed_switch_button_direction : public shape
{
public:
	pressed_switch_button_direction(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "PRESSED SWITCH BUTTON DIRECTION";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(14);
		circle(x , y-1 , 10);
		setfillpattern(p , 14);
		floodfill(x , y-1 , 14);
		circle(x , y+2 , 10);

		shape::show();
	}
};
class key : public shape
{
public:
	key(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "KEY";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		shape::show();
		setfillpattern(p , 9);
		floodfill(x-19 , y-19 , 15);

		int k = 6;
		setcolor(k);
		circle(x , y-5 , 8);
		circle(x , y-5 , 5);
		setfillpattern(p , k);
		floodfill(x , y+1 , k);
		rectangle(x-1 , y+3 , x+1 , y+15);
		setfillpattern(p , k);
		floodfill(x , y+9 , k);

		shape::show();
	}
};
class lock : public shape
{
public:
	lock(int ix , int iy)
	{
		x = ix;
		y = iy;
		name = "LOCK";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		shape::show();
		setfillpattern(p , 9);
		floodfill(x-19 , y-19 , 15);

		int k = 6;
		setcolor(k);
		int sh[] = {x-1 , y-15 , x+14  , y , x+8 , y+15 , x-9 , y+15 , x-15 , y , x-1 , y-15};
		drawpoly(6 , sh);
		setfillpattern(p , k);
		floodfill(x , y , k);
		setcolor(0);
		rectangle(x-5 , y-2 , x+4 , y+7);
		rectangle(x-6 , y-3 , x+5 , y+8);
		circle(x , y+3 , 5);

		shape::show();
	}
};
class end_point : public shape
{
public:
	end_point(int ix , int iy) 
	{
		x = ix;
		y = iy;
		name = "END POINT";
	}
	void show()
	{
		char p[8]={32767,32767,32767,32767,32767,32767,32767,32767};
		setcolor(0);
		rectangle(x-20 , y-20 , x+20 , y+20);
		setfillpattern(p , 0);
		floodfill(x , y , 0);

		setcolor(12);
		circle(x , y , 15);
		circle(x , y , 10);
		circle(x , y , 5);
		line(x-15 , y , x+15 , y);
		line(x , y-15 , x , y+15);

		shape::show();
	}
};
class game
{
public:
	int x , y;
	string stemp;
	int count_carrot;
	bool have_key;
	shape* A[15][10];
public:	
	void creat_mission(string file_creat , string file_start)
	{
		int i , j;
		char del;
		char str[80];
		ifstream in1(file_creat);
		in1.unsetf(ios :: skipws);
		while( !in1.eof() )
		{
			in1 >> i >> del >> j >> del;
			in1.getline(str , 80);

			if(strcmp(str , "CARROT") == 0)
				A[i][j] = new carrot(i*40+20 , j*40+20);
			else if(strcmp(str , "GRASS") == 0)
				A[i][j] = new grass(i*40+20 , j*40+20);
			else if(strcmp(str , "SPACE") == 0)
				A[i][j] = new space(i*40+20 , j*40+20);
			else if(strcmp(str , "BOBBY") == 0)
				A[i][j] = new bobby(i*40+20 , j*40+20);
			else if(strcmp(str , "INACTIVE TRAP") == 0)
				A[i][j] = new inactive_trap(i*40+20 , j*40+20);
			else if(strcmp(str , "ACTIVE TRAP") == 0)
				A[i][j] = new active_trap(i*40+20 , j*40+20);
			else if(strcmp(str , "VERTICAL PASSAGE") == 0)
				A[i][j] = new vertical_passage(i*40+20 , j*40+20);
			else if(strcmp(str , "HORIZONTAL PASSAGE") == 0)
				A[i][j] = new horizontal_passage(i*40+20 , j*40+20);
			else if(strcmp(str , "RIGHT DIRECTION") == 0)
				A[i][j] = new right_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "LEFT DIRECTION") == 0)
				A[i][j] = new left_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "UP DIRECTION") == 0)
				A[i][j] = new up_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "DOWN DIRECTION") == 0)
				A[i][j] = new down_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "NOT PRESSED SWITCH BUTTON PASSAGE") == 0)
				A[i][j] = new not_pressed_switch_button_passage(i*40+20 , j*40+20);
			else if(strcmp(str , "PRESSED SWITCH BUTTON PASSAGE") == 0)
				A[i][j] = new pressed_switch_button_passage(i*40+20 , j*40+20);
			else if(strcmp(str , "NOT PRESSED SWITCH BUTTON DIRECTION") == 0)
				A[i][j] = new not_pressed_switch_button_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "PRESSED SWITCH BUTTON DIRECTION") == 0)
				A[i][j] = new pressed_switch_button_direction(i*40+20 , j*40+20);
			else if(strcmp(str , "KEY") == 0)
				A[i][j] = new key(i*40+20 , j*40+20);
			else if(strcmp(str , "LOCK") == 0)
				A[i][j] = new lock(i*40+20 , j*40+20);
			else if(strcmp(str , "END POINT") == 0)
				A[i][j] = new end_point(i*40+20 , j*40+20);		
		}
		in1.close();

		//display
		for(i=0 ; i<15 ; i++)
			for(j=0 ; j<10 ; j++)
				A[i][j] -> show();

		string s;
		ifstream in2(file_start);
		in2.unsetf(ios :: skipws);
		in2 >> x >> del >> y >> del;
		in2.getline(str , 80);
		in2.getline(str , 80);
		int len = strlen(str);
		for(int i=0;i<len;i++)
			s.append(1 , str[i]);
		stemp = s;
		in2 >> count_carrot >> del;
		in2 >> have_key;
		in2.close();

	}
	void motion(char ch)
	{
		int dx = 0 , dy = 0;
		bool check = false;
		if(ch == -32)
		{
			char ch2 = getch();
			switch (ch2)
			{
			case 72 :
				dy = -40;		check = motion_possible(dx , dy , stemp);		break;
			case 80:
				dy = 40;		check = motion_possible(dx , dy , stemp);		break;
			case 75:
				dx = -40;		check = motion_possible(dx , dy , stemp);		break;
			case 77 :
				dx = 40;		check = motion_possible(dx , dy , stemp);		break;
			}
		}

		if(check == true)
		{
			int i = (x-20)/40;
			int j = (y-20)/40;
			change_shape(i , j , stemp);
			A[i][j] -> show();

			x += dx;
			y += dy; 

			i = (x-20)/40;
			j = (y-20)/40;

			stemp = A[i][j] -> getname();

			bool death = false;

			while(stemp == "DOWN DIRECTION")
			{
				A[i][j] = new bobby(x , y);
				A[i][j] -> show();
				delay(400);
				A[i][j] = new down_direction(x , y);
				A[i][j] -> show();
				y += 40;
				j = (y-20)/40;
				stemp = A[i][j] -> getname();
			}
			while(stemp == "UP DIRECTION")
			{
				A[i][j] = new bobby(x , y);
				A[i][j] -> show();
				delay(400);
				A[i][j] = new up_direction(x , y);
				A[i][j] -> show();
				y -= 40;
				j = (y-20)/40;
				stemp = A[i][j] -> getname();
			}
			while(stemp == "RIGHT DIRECTION")
			{
				A[i][j] = new bobby(x , y);
				A[i][j] -> show();
				delay(400);
				A[i][j] = new right_direction(x , y);
				A[i][j] -> show();
				x += 40;
				i = (x-20)/40;
				stemp = A[i][j] -> getname();
			}
			while(stemp == "LEFT DIRECTION")
			{
				A[i][j] = new bobby(x , y);
				A[i][j] -> show();
				delay(400);
				A[i][j] = new left_direction(x , y);
				A[i][j] -> show();
				x -= 40;
				i = (x-20)/40;
				stemp = A[i][j] -> getname();
			}
			if(stemp == "ACTIVE TRAP")
				death = true;
			else if(stemp == "CARROT")
			{
				stemp = "SPACE";
				A[i][j] = new space(x , y);
				A[i][j] -> show();
				count_carrot --;
			}
			else if(stemp == "KEY")
			{
				stemp = "SPACE";
				A[i][j] = new space(x , y);
				A[i][j] -> show();
				have_key = true;
			}
			else if(stemp == "LOCK")
			{
				A[i][j] = new bobby(x , y);
				A[i][j] -> show();
				stemp = "SPACE";
				A[i][j] = new space(x , y);
				A[i][j] -> show();
				have_key = false;
			}
			else if(stemp == "INACTIVE TRAP")
			{
				stemp = "ACTIVE TRAP";
				A[i][j] = new active_trap(x , y);
			}
			else if(stemp == "VERTICAL PASSAGE"  ||  stemp == "HORIZONTAL PASSAGE")
			{
				if(stemp == "VERTICAL PASSAGE")
					A[i][j] = new horizontal_passage(x , y);
				if(stemp == "HORIZONTAL PASSAGE")
					A[i][j] = new vertical_passage(x , y);

				stemp = A[i][j] -> getname();
			}
			else if(stemp == "NOT PRESSED SWITCH BUTTON PASSAGE")
			{
				stemp = "PRESSED SWITCH BUTTON PASSAGE";
				A[i][j] = new pressed_switch_button_passage(x , y);

				string s;
				for(int a=0 ; a<15 ; a++)
					for(int b=0 ; b<10 ; b++)
					{
						if(a == i  &&  b == j)
							continue;
						s = A[a][b] -> getname();
						if(s == "VERTICAL PASSAGE")
						{
							A[a][b] = new horizontal_passage(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(s == "HORIZONTAL PASSAGE")
						{
							A[a][b] = new vertical_passage(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(s == "PRESSED SWITCH BUTTON PASSAGE")
						{
							A[a][b] = new not_pressed_switch_button_passage(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(s == "NOT PRESSED SWITCH BUTTON PASSAGE")
						{
							A[a][b] = new pressed_switch_button_passage(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
					}
			}
			else if(stemp == "NOT PRESSED SWITCH BUTTON DIRECTION")
			{
				stemp = "PRESSED SWITCH BUTTON DIRECTION";
				A[i][j] = new pressed_switch_button_direction(x , y);
				string ss;
				for(int a=0 ; a<15 ; a++)
					for(int b=0 ; b<10 ; b++)
					{
						if(a == i  &&  b == j)
							continue;
						ss = A[a][b] -> getname();
						if(ss == "RIGHT DIRECTION")
						{
							A[a][b] = new left_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(ss == "LEFT DIRECTION")
						{
							A[a][b] = new right_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(ss == "UP DIRECTION")
						{
							A[a][b] = new down_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(ss == "DOWN DIRECTION")
						{
							A[a][b] = new up_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(ss == "PRESSED SWITCH BUTTON DIRECTION")
						{
							A[a][b] = new not_pressed_switch_button_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
						if(ss == "NOT PRESSED SWITCH BUTTON DIRECTION")
						{
							A[a][b] = new pressed_switch_button_direction(a*40+20 , b*40+20);
							A[a][b] -> show();
						}
					}
			}

			A[i][j] = new bobby(x , y);
			A[i][j] -> show();

			if(death == true)
			{
				system("cls");
				cout << "\n\n\n\t\t\t" << "YOU LOSE";
				getch();
				exit(0);
			}
		}
	}
	bool motion_possible(int dx , int dy , string stemp)
	{
		int i = (x-20)/40;
		int j = (y-20)/40;
		if(stemp == "HORIZONTAL PASSAGE"  &&  dx != 0)
			return false;
		if(stemp == "VERTICAL PASSAGE"  &&  dy != 0)
			return false;

		i = (x+dx-20)/40;
		j = (y+dy-20)/40;
		string s = A[i][j] -> getname();
		if(s == "DOWN DIRECTION"  &&  dy == -40)
			return false;
		else if(s == "UP DIRECTION"  &&  dy == 40)
			return false;
		else if(s == "RIGHT DIRECTION"  &&  dx == -40)
			return false;
		else if(s == "LEFT DIRECTION"  &&  dx == 40)
			return false;
		else if(s == "GRASS")
			return false;
		else if(s == "HORIZONTAL PASSAGE"  &&  dy != 0)
			return false;
		else if(s == "VERTICAL PASSAGE"  &&  dx != 0)
			return false;
		else if (s == "LOCK"  &&  have_key == false)
			return false;

		return true;
	}
	void change_shape(int i , int j , string s)
	{
		if(s == "SPACE")
			A[i][j] = new space(x , y);
		else if(s == "END POINT")
			A[i][j] = new end_point(x , y);
		else if(s == "INACTIVE TRAP")
			A[i][j] = new inactive_trap(x , y);
		else if(s == "ACTIVE TRAP")
			A[i][j] = new active_trap(x , y);
		else if(s == "VERTICAL PASSAGE")
			A[i][j] = new vertical_passage(x , y);
		else if(s == "HORIZONTAL PASSAGE")
			A[i][j] = new horizontal_passage(x , y);
		else if(s == "RIGHT DIRECTION")
			A[i][j] = new right_direction(x , y);
		else if(s == "LEFT DIRECTION")
			A[i][j] = new left_direction(x , y);
		else if(s == "UP DIRECTION")
			A[i][j] = new up_direction(x , y);
		else if(s == "DOWN DIRECTION")
			A[i][j] = new down_direction(x , y);
		else if(s == "RIGHT DIRECTION")
			A[i][j] = new right_direction(x , y);
		else if(s == "LEFT DIRECTION")
			A[i][j] = new left_direction(x , y);
		else if(s == "NOT PRESSED SWITCH BUTTON PASSAGE")
			A[i][j] = new not_pressed_switch_button_passage(x , y);
		else if(s == "PRESSED SWITCH BUTTON PASSAGE")
			A[i][j] = new pressed_switch_button_passage(x , y);
		else if(s == "NOT PRESSED SWITCH BUTTON DIRECTION")
			A[i][j] = new not_pressed_switch_button_direction(x , y);
		else if(s == "PRESSED SWITCH BUTTON DIRECTION")
			A[i][j] = new pressed_switch_button_direction(x , y);
		else if(s == "KEY")
			A[i][j] = new key(x , y);
		else if(s == "LOCK")
			A[i][j] = new lock(x , y);
	}
	void gaming()
	{
loop :
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t\t1 ) NEW GAME" << endl;
		cout << "\t\t\t2 ) LOUD GAME"<< endl;
		cout << "\t\t\t3 ) HELP" << endl;
		cout << "\t\t\t4 ) EXIT" << endl;
		cout << "\n\n\nENTER THE NUMBER :";
		int t;		cin >> t;
		int gd = DETECT , gm;
		system("cls");
		int Y = 100;
		switch (t)
		{
		case 1 :
			initgraph(&gd , &gm , "");
			creat_mission("creat mission1.txt" , "start mission1.txt");
			break;
		case 2 :
			initgraph(&gd , &gm , "");
			creat_mission("save mission1.txt" , "save start1.txt");	
			break;
		case 3 :
			initgraph(&gd , &gm , "");
			shape* help[18];
			help[0] = new carrot(40 , 40);
			print_in_graphic_page(70 , 30 , "CARROT");
			help[1] = new end_point(40 , 100);
			print_in_graphic_page(70 , 90 , "END POINT");
			help[2] = new inactive_trap(40 , 160);
			help[3] = new active_trap(100 , 160);
			print_in_graphic_page(130 , 150 , "TRAP");
			help[4] = new vertical_passage(40 , 220);
			help[5] = new horizontal_passage(100 , 220);
			print_in_graphic_page(130 , 210 , "PASSAGES");
			help[6] = new left_direction(40 , 340);
			help[7] = new right_direction(100 , 340);
			help[8] = new up_direction(160 , 340);
			help[9] = new down_direction(220 , 340);
			print_in_graphic_page(250 , 330 , "DIRECTIONS");
			help[10] = new not_pressed_switch_button_passage(40 , 280);
			help[11] = new pressed_switch_button_passage(100 , 280);
			print_in_graphic_page(130 , 270 , "PASSAGE SWITCHES");
			help[12] = new not_pressed_switch_button_direction(40 , 400);
			help[13] = new pressed_switch_button_direction(100 , 400);
			print_in_graphic_page(130 , 390 , "DIRECTION SWITCHES");
			help[14] = new key(40 , 450);
			help[15] = new lock(100 , 450);
			print_in_graphic_page(130 , 440 , "KEY AND LOCK");
	
			for(int i=0 ; i<16 ; i++)
				help[i] -> show();
			cout << "Press the any key than return the menu game ...";
			getch();
			closegraph();
			goto loop;
			break;
			

		case 4 :
			cout << "\n\n\n\n\t\t\t" << "GOOD BYE";
			getch();
			exit(0);
			break;
		}
		cout << "\n\n\n" << "\t\t\t" << "s ) SAVE GAME"; 
		cout << "\n\n\n" << "\t\t\t" << "r ) RESTART GAME";
		char ch;
		while(true)
		{
			ch = getch();

			if(ch == 's')
			{
				save_mission("save mission1.txt" , "save start1.txt");
				system("cls");
				cout << "\nTHE MISSION SAVED.";
				cout << "\n\n\n" << "DO YOU WANT TO CONTINUE ? (y/n)";
				char c = getch();
				switch (c)
				{
				case 'y':
					system("cls");
					cout << "\n\n\n" << "\t\t\t" << "s ) SAVE GAME";
					cout << "\n\n\n" << "\t\t\t" << "r ) RESTART GAME";
					break;
				case 'n':
					system("cls");
					cout << "\n\n\n\n\t\t\t" << "GOOD BYE";
					getch();
					exit(0);
					break;
				}
			}

			if(ch == 'r')
			{
				closegraph();
				int gd = DETECT , gm;
				initgraph(&gd , &gm , "");
				creat_mission("creat mission1.txt" , "start mission1.txt");
			}

			motion(ch);
			if(count_carrot == 0  &&  stemp == "END POINT")
			{
				system("cls");
				cout << "\n\n\n\t\t\t" << "YOU WIN";
				break;
			}
		}
	}
	void save_mission(string save_mission , string save_start)
	{
		int i , j;
		string sname;
		ofstream out1(save_mission);
		for(i=0 ; i<15 ; i++)
			for(j=0 ; j<10; j++)
			{
				if(i == 14  &&  j == 9)
					break;
				sname = A[i][j] -> getname();
				out1 << i << ' ' << j << ' ' << sname << '\n';
			}
		sname = A[14][9] -> getname(); 
		out1 << '1' << '4' << ' ' << '9' << ' ' << sname;
		out1.close();

		ofstream out2(save_start);
		out2 << x << ' ' << y << ' ' << '\n' 
			 << stemp << '\n'
			 << count_carrot << '\n'
			 << have_key;
		out2.close();
	}
};

int main()
{

	game g;
	g.gaming();

	getch();
	closegraph();
	return 0;
}

void print_in_graphic_page(int x , int y , char sp[])
{
	char str[5] , temp[2];
	temp[1] = 0;
	setcolor(14);
	settextstyle(4 , 0 , 10);
	for(int i=0;i<strlen(sp);i++)
	{
		temp[0] = sp[i];
		strcpy(str , temp);
		if(sp[i] == 'I')
		{
			outtextxy(x+i*10+5 , y , str);
			continue;
		}
		outtextxy(x+i*10 , y , str);
	}
}