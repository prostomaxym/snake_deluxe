#ifndef SNAKE_SNAKE_H_
#define SNAKE_SNAKE_H_

#include <vector>

#include "Fruct.h"
#include "Settings.h"
#include "Renderer.h"

enum class Direction
{
	UP,
	LEFT,
	RIGHT,
	DOWN
};

class Snake
{
public:
	Direction dir;

	Snake();

	void killSnake();
	void rebuildSnake();
	void lengthenSnake();
	void updateSnakeTail();
	void updateSnakeHead();
	void updateBorderCross();
	bool checkHeadCollision();

private:
	friend class Renderer;
	friend class Fruct;

	std::vector <int> x;
	std::vector <int> y;
	int length;
};
#endif //SNAKE_FRUCT_H_

