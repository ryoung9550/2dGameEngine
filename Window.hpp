#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include "GeObj.hpp"
#include "Texture.hpp"
#include "DrawObj.hpp"
#include <string>
#include <SDL2/SDL.h>
#include <vector>

class Window : public GeObj 
{
protected:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::string title;
	int xPos;
	int yPos;
	int width;
	int height;
	bool visible;
	std::vector<DrawObj*> drawList;
	static std::vector<Window*> windowList;
public:
	Window(std::string = "Window");
	~Window();
	void update();
	void isVisible(const bool);
	void addDrawable(DrawObj*);
	std::vector<Window*>& getWindowList();
};

#endif // _WINDOW_HPP
