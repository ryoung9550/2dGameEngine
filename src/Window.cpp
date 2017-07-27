#include "GeObj.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

std::vector<Window*> Window::windowList;

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
			if (makeWindow())
				visible = false;
		}
	}
}

int Window::makeWindow()
{
	window = SDL_CreateWindow(title.c_str(),
				xPos,
				yPos,
				width,
				height,
				0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	for (auto it = drawList.begin(); it != drawList.end(); it++) {
		addDrawable(*it);
	}
	return !(renderer && window);
}

int Window::destroyWindow()
{
	visible = false;
	for (auto it = drawList.begin(); it != drawList.end(); it++) {
		(*it)->destroyTexture();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return (renderer || window);
}

void Window::isVisible(const bool set) { visible = set; };

void Window::resize(const int width, const int height)
{
	this->width = width;
	this->height = height;
	destroyWindow();
	makeWindow();
}

void Window::addDrawable(DrawObj* drawable)
{
	drawable->createTexture(renderer);
	drawList.push_back(drawable);
}

std::vector<Window*>& Window::getWindowList() { return windowList; }
