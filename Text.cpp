#include "Text.h"

void Text::glWrite(float x, float y, int* font, std::string text) 
{
	glRasterPos2f(x, y);
	for (size_t i = 0; i <text.size(); i++)
		glutBitmapCharacter(font, (int)text[i]);
}

void Text::scoreRestart()
{
	this->scoreInt = 0;
}

void Text::scoreIncrease()
{
	this->scoreInt++;
}

void Text::scoreValueToStr()
{
	this->scoreStr = std::to_string(this->scoreInt);
}

std::string Text::getScoreStr()
{
	return this->scoreStr;
}