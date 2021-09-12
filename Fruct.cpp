#include "Fruct.h"

Fruct::Fruct()
{
	this->x = rand() % Settings::M;
	this->y = rand() % Settings::N;
}

void Fruct::newFruct()
{
	this->x = rand() % Settings::M;
	this->y = rand() % Settings::N;
}

bool Fruct::eatFructCheck(Snake s)
{
	if ((s.x[0] == this->x || s.x[1] == this->x)
		&& (s.y[0] == this->y || s.y[1] == this->y))
	{
		this->newFruct();
		//Protection from spawning apple on a surface of snake
		while ((std::find(s.x.begin(), s.x.end(), this->x) != s.x.end()) &&
			(std::find(s.y.begin(), s.y.end(), this->y) != s.y.end()))
		{
			this->newFruct();
		}
		return true;
	}
	else return false;
}