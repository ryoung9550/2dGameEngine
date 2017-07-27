#include "GeInit.hpp"
#include "Window.hpp"
#include "DrawObj.hpp"

#include <SDL2/SDL.h>

int main(int /*argc*/, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	{

		Window win;
		DrawObj thing1("test/thing1.bmp");
		win.isVisible(true);
	
		for (int i = 0; i < 5000; ++i) {
			win.update();
		}
	}	
	SDL_Quit();
	return 0;
}
