#include "GeInit.hpp"
#include "Window.hpp"
#include "DrawObj.hpp"

#include <SDL2/SDL.h>

int main(int /*argc*/, char** /*argv*/)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	{

		Window win("window");
		DrawObj thing1("test/thing1.bmp");
		win.addDrawable(&thing1);
		win.resize(320, 240);
		win.isVisible(true);
	
		while (win.isRunning()) {
			win.update();
		}
	}	
	SDL_Quit();
	return 0;
}
