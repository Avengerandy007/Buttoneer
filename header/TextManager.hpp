#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>
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
	static const std::string possibleKeys;
	std::vector<TextLine*> lines;
	std::vector<TextLine*> preRecordedLines();
	void Start();
	~TextManager();
	void Render();
	void MoveTextUp();
	void CreateText(std::string msg);
	void CreateError();
	static char GetRandomChar();
};
