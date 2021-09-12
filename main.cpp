#include <time.h>

#include <glut.h>

#include "Fruct.h"
#include "Renderer.h"
#include "Settings.h"
#include "Snake.h"
#include "Sound.h"
#include "Text.h"

enum class Gamemode
{
	GAMEPLAY,
	START_SCREEN,
	END_SCREEN
}mode;

//default classes init
Snake s;  //snake
Fruct a[Settings::apple_number];  //apples
Text score; //score
Renderer window; //window renderer
Sound backSound("theme.wav", 0.1); //background music (filename, volume)

//function prototypes
void keyboard(int key, int a, int b);
void pause(unsigned char key, int a, int b);
void update();
void render();
void gameloop(int);

int main(int argc, char** argv)
{
	srand(time(0));
	int i = 0;
	//Init background sound 
	backSound.soundInit();

	//Gamemode init
	mode = Gamemode::START_SCREEN;

	//glut functions setup
	glutDisplayFunc(render);
	glutTimerFunc(60, gameloop, 0);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(pause);

	//Game loop
	glutMainLoop();

	return 0;
}

void keyboard(int key, int a, int b)
{
	switch (key)
	{
	case GLUT_KEY_UP: if (s.dir != Direction::DOWN)s.dir = Direction::UP; break;
	case GLUT_KEY_RIGHT: if (s.dir != Direction::LEFT)s.dir = Direction::RIGHT; break;
	case GLUT_KEY_LEFT: if (s.dir != Direction::RIGHT)s.dir = Direction::LEFT; break;
	case GLUT_KEY_DOWN: if (s.dir != Direction::UP)s.dir = Direction::DOWN; break;
	}
}

void pause(unsigned char key, int a, int b)
{
	if (mode == Gamemode::START_SCREEN && key == 13) //key 13- ENTER
	{
		mode = Gamemode::GAMEPLAY; //start
	}
	else if (mode == Gamemode::END_SCREEN && key == 13) //reset
	{
		s.killSnake();
		s.rebuildSnake();
		score.scoreRestart();
		mode = Gamemode::GAMEPLAY;
	}
}

void update()
{
	//Snake update
	s.updateSnakeTail();
	s.updateSnakeHead();
	s.updateBorderCross();
	if (s.checkHeadCollision())
	{
		mode = Gamemode::END_SCREEN;
	}

	//Fruct collision check
	for (size_t i=0; i < Settings::apple_number; i++)
	{
		if (a[i].eatFructCheck(s))
		{
			s.lengthenSnake();
			score.scoreIncrease();
		}
	}

	//Score update
	score.scoreValueToStr();
}

void render()
{
	glClearColor(0.4, 0.5, 0.9, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	window.drawField();
	window.drawSnake(s);
	for (int i = 0; i < Settings::apple_number; i++)
	{
		window.drawFruct(a[i]);
	}
	window.drawScore(score);

	glFlush();
}

void gameloop(int = 0)
{
	if (mode == Gamemode::START_SCREEN) window.drawStartScreen(score);
	else if (mode == Gamemode::END_SCREEN) window.drawEndScreen(score);
	else
	{
		render();
		update();
	}
	glutTimerFunc(60, gameloop, 0);
}