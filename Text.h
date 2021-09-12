#ifndef SNAKE_TEXT_H_
#define SNAKE_TEXT_H_

#include <string>

#include <glut.h>

#include "Settings.h"

class Text
{
public:
	void glWrite(float x, float y, int* font, std::string text);
	void scoreRestart();
	void scoreIncrease();
	void scoreValueToStr();
	std::string getScoreStr();

private:
	int scoreInt = 0;
	std::string scoreStr;
};
#endif  // SNAKE_TEXT_H_
