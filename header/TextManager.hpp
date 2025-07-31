#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include <vector>

class TextLine{
	SDL_Texture* texture;
protected:
	SDL_Color color;
	void CreateTexture();
	
public:
	SDL_Surface* surface;
	SDL_Rect rect;
	const char* text;
	void Render();
	TextLine(const char* msg, int Y);
	TextLine();
	virtual ~TextLine();
};

class ErrorLine : public TextLine{
public:
	ErrorLine(const char* msg, int Y);
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
	void CreateError(std::string msg);
	static char GetRandomChar();
};
