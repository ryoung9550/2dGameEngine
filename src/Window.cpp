#include "GeObj.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

std::vector<Window*> Window::windowList;

Window::Window(std::string title) : title(title),
	xPos(SDL_WINDOWPOS_UNDEFINED),
	yPos(SDL_WINDOWPOS_UNDEFINED),
	width(200),
	height(200),
	visible(false),
	running(true) {}

Window::~Window() {
	SDL_DestroyWindow(window);
}

void Window::update() 
{
	if (window && visible) {
		
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		for (auto it = drawList.begin(); it != drawList.end(); it++) {
			(*it)->draw();
		}
		SDL_RenderPresent(renderer);
	} else {
		if (visible) {
			if (makeWindow()) // If there was a problem making the window
				visible = false; // Reset visible
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

bool Window::isRunning() { return running; }

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
	if (visible) {
		destroyWindow();
		makeWindow();
	}
}

void Window::addDrawable(DrawObj* drawable)
{
	drawable->createTexture(renderer);
	drawList.push_back(drawable);
}

std::vector<Window*>& Window::getWindowList() { return windowList; }
