#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

#include "GeObj.hpp"
#include <SDL2/SDL.h>
#include <string>

struct TextureSize
{
	unsigned w, h;
};

class Texture : public GeObj
{
protected:
	SDL_Texture *texture;
	SDL_Surface *bitMap;
	unsigned textureW;
	unsigned textureH;
	std::string texturePath;
public:
	TextureSize getTextureSize();
	int createTexture(SDL_Renderer*);
	int destroyTexture();
	void updateTextureSize();
	Texture(std::string);
	~Texture();
};


#endif // _TEXTURE_HPP
