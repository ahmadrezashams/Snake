#include "stdafx.h"
#include "Food.h"

Point Food::CreateFood()
{
	time_t t;
	srand(time(&t));
	p.x = (rand() % 80) ;
	p.y = (rand() % 24) ;
	return p;
}

Point Food::PointFood()
{
	return p;
}
