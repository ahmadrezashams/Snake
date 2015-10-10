#pragma once
#include "Point.h"

class Snake
{
public:
	Snake();
	void Move(int);
	int GetLength();
	void IncLength();
	void Relocate();
	void Reset();
	Point *Location();
private:
	int length;
	Point *location;
	enum key{ up, down, left, right };
	
};

