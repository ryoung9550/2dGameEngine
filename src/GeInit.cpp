#include "geInit.hpp"

int ge::init() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	return 0;
}
