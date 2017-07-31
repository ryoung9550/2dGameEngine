#include "GeInit.hpp"
#include "Window.hpp"
#include "DrawObj.hpp"
#include "GeInit.hpp"
#include <SDL2/SDL.h>

int main(int /*argc*/, char** /*argv*/)
{
	ge::init();
	{

		Window win;
		win.isVisible(true);
		DrawObj thing1("thing1.bmp");
		win.addDrawable(&thing1);
	
		while (win.isRunning()) {
			win.update();
		}
	} // Body end so window is destroyed before ge::quit()
	ge::quit();
	return 0;
}
