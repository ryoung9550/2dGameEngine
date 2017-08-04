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
public:
	DrawObj(std::string);
	~DrawObj();
	void setRenderer(SDL_Renderer*);
	virtual void draw();
	void moveRel(int i, int j);
	void moveAbs(int i, int j);
};

#endif // _DRAWOBJ_HPP
