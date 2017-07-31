#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

#include "GeObj.hpp"
#include <SDL2/SDL.h>
#include <string>

struct TextureSize
{
	int w, h;
};

class Texture : public GeObj
{
protected:
	SDL_Texture *texture;
	SDL_Surface *bitMap;
	int textureW;
	int textureH;
	std::string texturePath;
	SDL_Renderer *renderer;
public:
	TextureSize getTextureSize();
	int createTexture(SDL_Renderer*);
	int destroyTexture();
	void updateTextureSize();
	Texture(std::string);
	~Texture();
};


#endif // _TEXTURE_HPP
