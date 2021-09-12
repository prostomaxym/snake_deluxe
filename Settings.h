#ifndef SNAKE_SETTINGS_H_
#define SNAKE_SETTINGS_H_

//default field size settings
struct Settings
{
	static const int M = 30, N = 20;  //cells number
	static const int Scale = 25;  // cell size in pixel
	static const int w = M * Scale;  //window width in pixel
	static const int h = N * Scale;  //window height in pixel
	static const int apple_number = 3;  // number of apples spawned
};  
#endif  // SNAKE_SETTINGS_H_