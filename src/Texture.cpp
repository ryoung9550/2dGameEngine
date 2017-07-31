#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

TextureSize Texture::getTextureSize()
{
	TextureSize size{textureW, textureH};
	return size;
}

void Texture::updateTextureSize()
{
	const unsigned bufferSize = 0x30;
	char inputBuffer[bufferSize];

	std::ifstream file(texturePath, std::istream::binary);
	file.read(inputBuffer, bufferSize);
	textureW = inputBuffer[0x12] | (inputBuffer[0x13] << 8) | (inputBuffer[0x14] << 16) | (inputBuffer[0x15] << 24);
	textureH = inputBuffer[0x16] | (inputBuffer[0x17] << 8) | (inputBuffer[0x18] << 16) | (inputBuffer[0x19] << 24);
	std::cout << "Texture Width: " << textureW << "  Texture Height: " << textureH << "\n";
}

int Texture::createTexture(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	texture = SDL_CreateTextureFromSurface(renderer, bitMap);
	return !texture;
}

int Texture::destroyTexture()
{
	SDL_DestroyTexture(texture);
	return !!texture;
}

Texture::Texture(std::string path) : texturePath(path), renderer(nullptr)
{
	bitMap = SDL_LoadBMP(texturePath.c_str());
	updateTextureSize();
}

Texture::~Texture()
{
	SDL_FreeSurface(bitMap);
	SDL_DestroyTexture(texture);
}
