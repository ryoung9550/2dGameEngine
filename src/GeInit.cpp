#include "GeInit.hpp"

int ge::init() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	return 0;
}

int ge::quit()
{
	SDL_Quit();
	return 0;
}
