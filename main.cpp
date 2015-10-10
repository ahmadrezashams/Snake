// main.cpp : Defines the entry point for the console application.
//


#include  "stdafx.h"
#include  "Point.h"
#include  "Food.h"
#include  <Windows.h>
#include  "Snake.h"
#include  <iostream>
#include  <conio.h>
#include <string>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;

Snake snake;
Food f;
Point lastsegment;
int Score;

unsigned int dir;

void gotoxy(Point p)
{
	COORD coord;
	coord.X = p.x;
	coord.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CreateFood()
{
	bool occupied;
	do
	{
		f.CreateFood();
		occupied = false;
		for (int i = 0; i < snake.GetLength(); i++)
		{
			if ((f.PointFood().x == snake.Location()[i].x) && (f.PointFood().y == snake.Location()[i].y))
				{
					occupied = true;
					break;
				}
		}
	} while (occupied == true);
}

void Check()
{
	if (f.PointFood().x == snake.Location()[0].x && f.PointFood().y == snake.Location()[0].y)
	{
		Score++;
		snake.IncLength();
		snake.Location()[snake.GetLength() - 1] = lastsegment;
		CreateFood();
	}
}
void  Key()
{
	if (dir == UP)
	{
		dir = UP;
		snake.Move(0);
	}
	else if (dir == DOWN){
		dir = DOWN;
		snake.Move(1);
	}
	else if (dir == LEFT){
		dir = LEFT;
		snake.Move(2);
	}
	else if (dir == RIGHT){
		dir = RIGHT;
		snake.Move(3);
	}
}
void timer()
{
	if (_kbhit()){
		dir = _getch();
		Key();
	}
	else	
		Key();

	system("cls");
	gotoxy(f.PointFood());
	cout << "$";
	for (int i = 0; i < snake.GetLength(); i++)
	{
		Point p;
		p.x=snake.Location()[i].x ;
		p.y = snake.Location()[i].y ;
		gotoxy(p);
		cout << "#";
		if ((snake.Location()[i].x == snake.Location()[0].x) && 
			(snake.Location()[i].y == snake.Location()[0].y) 
			&& (i > 0))
		{
			system("cls");
			snake.Reset();
			dir = NULL;
			return;
		}
	}
	Check();
	
}
void loading()
{
	Point p;
	p.x = 36;
	p.y = 15;
	gotoxy(p);
	cout << "Loading...";
	p.x = 30;
	p.y = 16;
	gotoxy(p);
	for (size_t i = 0; i < 20; i++)
	{
		Sleep(200);
		cout << char(177);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleTitle(TEXT("Snake Game"+Score));
	lastsegment = snake.Location()[snake.GetLength() - 1];
	CreateFood();
	dir = 3;
	Score = 0;
	loading();
	while (true)
	{
			Sleep(120);
			timer();
	}

	return 0;
}

