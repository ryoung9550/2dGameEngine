#ifndef _DRAWOBJ_HPP
#define _DRAWOBJ_HPP

#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <string>

class DrawObj : public Texture
{
protected:
	int xPosDraw;
	int yPosDraw;
	int widthDraw;
	int heightDraw;
	SDL_Renderer* renderer;
public:
	DrawObj(std::string);
	~DrawObj();
	void setRenderer(SDL_Renderer*);
	void draw();
};

#endif // _DRAWOBJ_HPP
