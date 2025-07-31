#include "../header/TextManager.hpp"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <ctime>
#include <iterator>
#include <memory>
#include <vector>
#include "../header/Global.hpp"

TTF_Font* TextManager::font = nullptr;
const std::string TextManager::possibleKeys = "abcdefghijklmnopqrstuvwxyz0123456789',./;`[]-=";

//Text line definitions

TextLine::TextLine(){}

TextLine::TextLine(const char* msg, int Y){
	UniVersalTextManager->lines.push_back(this);
	color = {255, 255, 255, 255};
	rect.x = 10;
	SDL_GetWindowSize(mainWindow->window, &rect.w, &rect.h);
	rect.w /= 2;
	rect.h /= 10;
	rect.y = Y;
	text = msg;
	CreateTexture();
}

void TextLine::CreateTexture(){
	surface = TTF_RenderUTF8_Blended_Wrapped(TextManager::font, text, color, rect.w);
	if(!surface) std::cerr<< "Could not create surface: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(mainWindow->renderer, surface);
	if(!texture) std::cerr<< "Could not create texture: " << SDL_GetError() << std::endl;
}

void TextLine::Render(){
	SDL_RenderCopy(mainWindow->renderer, texture, nullptr, &rect);
}

TextLine::~TextLine(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

//Error text
ErrorLine::ErrorLine(const char* msg, int Y){
	UniVersalTextManager->lines.push_back(this);
	color = {255, 0, 0, 255};
	rect.x = 10;
	SDL_GetWindowSize(mainWindow->window, &rect.w, &rect.h);
	rect.h /= 5;
	rect.y = Y;
	text = msg;
	CreateTexture();
}
//Text manager
void TextManager::CreateText(std::string msg){
	int y = 0;
	if (!lines.empty()){
		y = lines.back()->rect.y + lines.back()->surface->h;
	}
	new TextLine(msg.c_str(), y);
	MoveTextUp();
}
void TextManager::CreateError(std::string msg){
	int y = 0;
	if (!lines.empty()){
		y = lines.back()->rect.y + lines.back()->surface->h;
	}
	new ErrorLine(msg.c_str(), y);
	MoveTextUp();
}

void TextManager::Start(){
	font = TTF_OpenFont("data/VT323.ttf", 120); 
	if (!font){
		std::cerr<< "Font could not be oppened: " << SDL_GetError() << std::endl;
	}
}

void TextManager::Render(){
	for(TextLine* line : lines){
		line->Render();
	}
}

void TextManager::MoveTextUp(){
	if (lines.size() == 0) return; 
	int currentWinH;
	SDL_GetWindowSize(mainWindow->window, nullptr, &currentWinH);
	if (lines[lines.size() - 1]->rect.y > currentWinH - lines[lines.size() - 1]->rect.h){
		auto it = lines.begin();
		while(it != lines.end()){
			TextLine* line = *it;
			line->rect.y -= line->rect.h;
			if (line->rect.y + line->surface->h < 0){
				delete line;
				it = lines.erase(it);
			}else{
				it++;
			}
		}
	}
}

TextManager::~TextManager(){
	for(TextLine* line : lines){
		delete line;
		line = nullptr;
	}
	lines.clear();
}

char TextManager::GetRandomChar(){
	srand(time(NULL));
	return possibleKeys[rand() % possibleKeys.size()];
}
