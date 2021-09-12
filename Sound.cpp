#include "Sound.h"

Sound::Sound(std::string name, float vol)
{
	this->filename = name;
	this->volume = vol;
}

void Sound::readWavFileIntoMemory(std::string fname, BYTE** pb, DWORD* fsize)
{
	std::ifstream f(fname, std::ios::binary);

	f.seekg(0, std::ios::end);
	int lim = f.tellg();
	*fsize = lim;
	*pb = new BYTE[lim];
	f.seekg(0, std::ios::beg);
	f.read((char*)*pb, lim);

	f.close();
}

void Sound::soundInit()
{
	float fVolume = this->volume;
	DWORD dwFileSize;
	BYTE* pFileBytes;

	readWavFileIntoMemory(this->filename, &pFileBytes, &dwFileSize);
	BYTE* pDataOffset = (pFileBytes + 40);

	__int16* p = (__int16*)(pDataOffset + 8);
	for (auto i = 80 / sizeof(*p); i < dwFileSize / sizeof(*p); i++) {
		p[i] = (float)p[i] * fVolume;
	}
	PlaySound((LPCWSTR)pFileBytes, NULL, SND_MEMORY | SND_LOOP | SND_ASYNC);
}
