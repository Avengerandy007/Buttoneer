#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <vector>

class TextLine{
	SDL_Surface* surface;
	SDL_Texture* texture;
	void CreateTexture();
protected:
	SDL_Color color;
	
public:
	SDL_Rect rect;
	const char* text;
	void Render();
	TextLine(const char* msg);
	~TextLine();
};

class ErrorLine : public TextLine{
public:
	ErrorLine();
};

class TextManager{
public:
	static TTF_Font* font;
	std::vector<TextLine*> lines;
	void Start();
	~TextManager();
	void MoveTextUp();
	void CreateText(std::string msg);
	void CreateError();
};
