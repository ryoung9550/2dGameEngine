#include "GeObj.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

Window::Window(std::string title) : title(title),
	xPos(SDL_WINDOWPOS_UNDEFINED),
	yPos(SDL_WINDOWPOS_UNDEFINED),
	width(0),
	height(0) {} 

Window::~Window() 
{
	SDL_DestroyWindow(window);
}

void Window::update() 
{
	if (window) {
		for (auto it = drawList.begin(); it != drawList.end(); it++) {
			(*it)->draw();
		}
	} else {
		if (visible) {
			window = SDL_CreateWindow(title.c_str(),
						xPos,
						yPos,
						width,
						height,
						0);
			renderer = SDL_CreateRenderer(window, -1, 0);
		}
	}
}

void Window::isVisible(const bool set) { visible = set; };

void Window::addDrawable(DrawObj* drawable)
{
	drawable->createTexture(renderer);
	drawList.push_back(drawable);
}

std::vector<Window*>& Window::getWindowList() { return windowList; }
