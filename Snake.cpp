#include "stdafx.h"
#include "Snake.h"


Snake::Snake()
{
	length = 5;
	location = new Point[25 * 25];
	Reset();
}

void Snake::IncLength()
{
	length++;
}

int Snake::GetLength()
{
	return length;
}
Point *Snake::Location()
{
	return location;
}
void Snake::Relocate()
{
	for (int i = length- 1; i >0; i--)
	{
		location[i] = location[i - 1];
	}

}
void Snake::Reset()
{
	length = 5;
	for (int i = 0; i < length; i++)
	{
		location[i].x = 12;
		location[i].y = 12;
	}
}
void  Snake::Move(int dir)
{
	
	switch (dir)
	{
	case key::up:
		Relocate();
		location[0].y--;
		if (location[0].y < 0)
			location[0].y += 25;
		break;
	case key::down:
		Relocate();
		location[0].y++;
		if (location[0].y > 24)
			location[0].y -= 25;
		break;
	case key::left:
		Relocate();
		location[0].x--;
		if (location[0].x < 0)
			location[0].x += 80;
		break;
	case key::right:
		Relocate();
		location[0].x++;
		if (location[0].x > 79)
			location[0].x -= 80;
		break;
	}


}
