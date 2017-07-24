#include <string>
#include "Texture.hpp"
#include "DrawObj.hpp"

DrawObj::DrawObj(std::string path) : Texture(path),
		xPosDraw(0),
		yPosDraw(0),
		widthDraw(textureW),
		heightDraw(textureH),
		renderer(nullptr) {}

void DrawObj::setRenderer(SDL_Renderer* renderer) { this->renderer = renderer; }

