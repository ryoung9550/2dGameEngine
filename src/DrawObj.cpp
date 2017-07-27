#include <string>
#include "Texture.hpp"
#include "DrawObj.hpp"
#include <SDL2/SDL.h>

DrawObj::DrawObj(std::string path) : Texture(path),
		xPosDraw(0),
		yPosDraw(0),
		widthDraw(textureW),
		heightDraw(textureH),
		renderer(nullptr) {}
	
DrawObj::~DrawObj()
{
	SDL_DestroyRenderer(renderer);
}

void DrawObj::setRenderer(SDL_Renderer* renderer) { this->renderer = renderer; }

void DrawObj::draw() 
{
	SDL_Rect destRect {widthDraw, heightDraw, (int) textureW, (int) textureH};
	SDL_RenderCopy(renderer, this->texture, NULL, &destRect);
}
