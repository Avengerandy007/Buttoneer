#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Window{
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	void Render();
	int Setup();
	~Window();
};
