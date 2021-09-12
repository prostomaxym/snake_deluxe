#include "Snake.h"

Snake::Snake()
{
	this->dir = Direction::RIGHT;
	this->length = 4;
	this->x.assign(this->length, 0);
	this->y.assign(this->length, 0);
	this->x[0] = 15;
	this->y[0] = 10;
}

void Snake::killSnake()
{
	this->x.clear();
	this->y.clear();
}

void Snake::rebuildSnake()
{
	this->dir = Direction::RIGHT;
	this->length = 4;
	this->x.assign(this->length, 0);
	this->y.assign(this->length, 0);
	this->x[0] = 15;
	this->y[0] = 10;
}

void Snake::lengthenSnake()
{
	this->length = this->length + 1;
	this->x.push_back(-10);
	this->y.push_back(-10);
}

void Snake::updateSnakeTail()
{
	for (size_t i = this->length - 1; i > 0; --i)
	{
		this->x[i] = this->x[i - 1];
		this->y[i] = this->y[i - 1];
	}
}

void Snake::updateSnakeHead()
{
	if (this->dir == Direction::UP) this->y[0] += 1;
	else if (this->dir == Direction::LEFT) this->x[0] -= 1;
	else if (this->dir == Direction::RIGHT) this->x[0] += 1;
	else if (this->dir == Direction::DOWN) this->y[0] -= 1;
}

void Snake::updateBorderCross()
{
	if (this->x[0] > Settings::M - 1) this->x[0] = 0;
	else if (this->x[0] < 0) this->x[0] = Settings::M - 1;
	else if (this->y[0] > Settings::N - 1) this->y[0] = 0;
	else if (this->y[0] < 0) this->y[0] = Settings::N - 1;
}

bool Snake::checkHeadCollision()
{
	for (int i = 1; i < this->length; i++)
	{
		if ((this->x[0] == this->x[i]) && (this->y[0] == this->y[i]))
		{
			return true;
		}
	}
	return false;
}