#include "Renderer.h"

//Base window settings
Renderer::Renderer()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Settings::w, Settings::h);
	glutCreateWindow("Snake Deluxe");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Settings::w, 0, Settings::h);
}

void Renderer::drawField()
{
	glColor3f(0.4, 0.5, 0.9);
	glBegin(GL_LINES);

	for (int i = 0; i < Settings::w; i += Settings::Scale)
	{
		glVertex2f(i, 0);
		glVertex2f(i, Settings::h);
	}

	for (int j = 0; j < Settings::h; j += Settings::Scale)
	{
		glVertex2f(0, j);
		glVertex2f(Settings::w, j);
	}
	glEnd();
}

void Renderer::drawSnake(Snake s)
{
	glColor3f(1, 0.2, 0);
	for (size_t i = 0; i < s.x.size(); i++)
	{
		glRectf(s.x[i] * Settings::Scale, s.y[i] * Settings::Scale,
			(s.x[i] + 1) * Settings::Scale, (s.y[i] + 1) * Settings::Scale);
	}
}

void Renderer::drawFruct(Fruct a)
{
	glColor3f(0, 0.9, 0);
	glRectf(a.x * Settings::Scale, a.y * Settings::Scale,
			(a.x + 1) * Settings::Scale, (a.y + 1) * Settings::Scale);
}

void Renderer::drawStartScreen(Text score)
{
	glFlush();

	glColor3f(0.2, 0.2, 0.2);
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(200, 300, Settings::w - 200, Settings::h - 300);

	glColor3f(0.8, 0.1, 0);
	score.glWrite((Settings::w / 2) - 100, Settings::h - 150,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Snake Deluxe v1.0");

	glColor3f(0.1, 0.5, 0.2);
	score.glWrite(Settings::w - 300, 50,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Jokur Corporation");

	glColor3f(0.9, 0.8, 0.7);
	score.glWrite((Settings::w / 2) - 100, Settings::h / 2,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Press ENTER to start");
}

void Renderer::drawEndScreen(Text score)
{
	glFlush();

	glColor3f(0.2, 0.2, 0.2);
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(200, 300, Settings::w - 200, Settings::h - 300);

	glColor3f(0.8, 0.1, 0);
	score.glWrite((Settings::w / 2) - 65, Settings::h - 150,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");

	glColor3f(0.8, 0.8, 0.7);
	score.glWrite((Settings::w / 2) - 85, Settings::h - 180,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Your score is");
	glColor3f(0.8, 0.8, 0.7);
	score.glWrite(Settings::w / 2 + 65, Settings::h - 180,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, score.getScoreStr());

	glColor3f(0.9, 0.8, 0.7);
	score.glWrite((Settings::w / 2) - 120, Settings::h / 2,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Press ENTER to restart");
}

void Renderer::drawScore(Text score)
{
	glColor3f(1, 1, 0);
	score.glWrite(Settings::w - 180, Settings::h - 40, (int*)GLUT_BITMAP_TIMES_ROMAN_24, "SCORE");
	score.glWrite(Settings::w - 70, Settings::h - 40, (int*)GLUT_BITMAP_TIMES_ROMAN_24, score.getScoreStr());
}