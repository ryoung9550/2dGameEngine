#include "GeInit.hpp"
#include "Window.hpp"
#include "DrawObj.hpp"

#include <SDL2/SDL.h>

int main(int /*argc*/, char** /*argv*/)
{
	{
		ge::init();

		Window win;
		DrawObj thing1("textures/texture1.bmp");
		win.addDrawable(&thing1);
		win.isVisible(true);
	
		for (int i = 0; i < 5000; ++i) {
			win.update();
		}
	}	
	ge::quit();	
	return 0;
}
