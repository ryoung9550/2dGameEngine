#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <fstream>

TextureSize Texture::getTextureSize()
{
	TextureSize size{textureW, textureH};
	return size;
}

void Texture::updateTextureSize()
{
	constexpr unsigned bufferSize = 0x30;
	char inputBuffer[bufferSize];
	std::ifstream file(texturePath.c_str());
	file.read(inputBuffer, bufferSize);
	textureW = inputBuffer[0x12];
	textureH = inputBuffer[0x16];
}

int Texture::createTexture(SDL_Renderer* renderer)
{
	texture = SDL_CreateTextureFromSurface(renderer, bitMap);
	return !texture;
}

int Texture::destroyTexture()
{
	SDL_DestroyTexture(texture);
	return !!texture;
}

Texture::Texture(std::string path) : texturePath(path) 
{
	bitMap = SDL_LoadBMP(texturePath.c_str());
}

Texture::~Texture()
{
	SDL_FreeSurface(bitMap);
	SDL_DestroyTexture(texture);
}
