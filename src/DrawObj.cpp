#include "Texture.hpp"
#include "DrawObj.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

DrawObj::DrawObj(std::string path) : Texture(path),
		xPosDraw(0),
		yPosDraw(0),
		widthDraw(textureW),
		heightDraw(textureH) {}
	
DrawObj::~DrawObj()
{
	SDL_DestroyRenderer(renderer);
}

void DrawObj::setRenderer(SDL_Renderer* renderer) { this->renderer = renderer; }

void DrawObj::draw() 
{
	SDL_Rect destRect {xPosDraw, yPosDraw, widthDraw, heightDraw};
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void DrawObj::moveRel(int i, int j)
{
	xPosDraw += i;
	yPosDraw += j;
}

void DrawObj::moveAbs(int i, int j)
{
	xPosDraw = i;
	yPosDraw = j;
}
