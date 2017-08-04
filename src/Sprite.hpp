#ifndef _SPRITE_HPP
#define _SPRITE_HPP

#include "DrawObj.hpp"

class Sprite : public DrawObj
{
private:
	int spriteSizeW; // individual size for the sprite in a texture
	int spriteSizeH;
	int currentSprite; // sprite is selected by row then goes to next. 
					   // sprites start at zero.
public:
	Sprite();
	void setSpriteSize(const int&, const int&);
	void draw();
};

#endif // _SPRITE_HPP
