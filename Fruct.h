#ifndef SNAKE_FRUCT_H_
#define SNAKE_FRUCT_H_

#include <algorithm>
#include <random>

#include "Settings.h"
#include "Snake.h"
#include "Renderer.h"

class Fruct
{
public:
	Fruct();

	void newFruct();
	bool eatFructCheck(Snake s);

private:
	friend class Snake;
	friend class Renderer;

	int x, y;
};
#endif //SNAKE_FRUCT_H_

