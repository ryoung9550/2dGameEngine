#include "GeObj.hpp"
#include "Window.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <vector>

std::vector<Window*> Window::windowList;

Window::Window(std::string title) : window(nullptr),
	renderer(nullptr),
	title(title),
	xPos(SDL_WINDOWPOS_UNDEFINED),
	yPos(SDL_WINDOWPOS_UNDEFINED),
	width(200),
	height(200),
	visible(false),
	running(true) 
{
} 

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Window::update() 
{
	if (window) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // fill background with black
		SDL_RenderClear(renderer);
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}
		for (auto it = drawList.begin(); it != drawList.end(); it++) {
			(*it)->draw();
		}
		SDL_RenderPresent(renderer);
		
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

void Window::isVisible(const bool set) { 
	visible = set; 
	update();
}

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

bool Window::isRunning() { return running; }

std::vector<Window*>& Window::getWindowList() { return windowList; }
