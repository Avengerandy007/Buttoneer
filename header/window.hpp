#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Window{
	SDL_Window* window;
	SDL_Renderer* renderer;
	void Render();
public:
	int Setup();
	~Window();
};
