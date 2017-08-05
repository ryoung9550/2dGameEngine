#include <SDL2/SDL.h>
#include <string>
#include "Sprite.hpp"

Sprite::Sprite(const int& spriteWidth, const int& spriteHeight, const std::string& path) : DrawObj(path), spriteSizeW(spriteWidth), spriteSizeH(spriteHeight) {}

void Sprite::setCurrentSprite(const int& spriteNum) { this->currentSprite = spriteNum; }

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
