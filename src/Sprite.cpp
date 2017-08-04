#include <SDL2/SDL.h>
#include "Sprite.hpp"

void Sprite::setSpriteSize(const int& sizeW, const int& sizeH)
{
	this->spriteSizeW = sizeW;
	this->spriteSizeH = sizeH;
}

void Sprite::draw()
{
	SDL_Rect sprite {currentSprite * spriteSizeW % textureW, 
                     currentSprite * spriteSizeW / textureW,
					 spriteSizeW,
					 spriteSizeH};
	SDL_Rect destRect {xPosDraw, yPosDraw, widthDraw, heightDraw};
	SDL_RenderCopy(renderer, texture, &sprite, &destRect);
}
