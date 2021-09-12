#ifndef SNAKE_RENDERER_H_
#define SNAKE_RENDERER_H_

#include <glut.h>

#include "Fruct.h"
#include "Settings.h"
#include "Snake.h"
#include "Text.h"

class Snake;
class Fruct;

class Renderer
{
public:
	Renderer();

	void drawField();
	void drawSnake(Snake s);
	void drawFruct(Fruct apple);
	void drawStartScreen(Text score);
	void drawEndScreen(Text score);
	void drawScore(Text score);
};
#endif  // SNAKE_RENDERER_H_
