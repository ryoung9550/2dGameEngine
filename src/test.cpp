#include "GeInit.hpp"
#include "Window.hpp"
#include "DrawObj.hpp"

#include <SDL2/SDL.h>

int main(int /*argc*/, char** /*argv*/)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	{

		Window win;
		win.isVisible(true);
		DrawObj thing1("thing1.bmp");
		win.addDrawable(&thing1);
	
		while (win.isRunning()) {
			win.update();
		}
	}	
	SDL_Quit();
	return 0;
}
