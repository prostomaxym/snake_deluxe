#ifndef SNAKE_SOUND_H_
#define SNAKE_SOUND_H_

#include <windows.h>

#include <fstream>
#include <string>

class Sound
{
public:
	Sound(std::string name, float vol);

	void readWavFileIntoMemory(std::string fname, BYTE** pb, DWORD* fsize);
	void soundInit();

private:
	std::string filename;
	float volume;
};
#endif
