#include "../header/window.hpp"
#include "../header/TextManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <iostream>

int Window::Setup(){
	window = nullptr;
	renderer = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "There was a problem initialising SDL2: " << SDL_GetError() << std::endl;
		return -1;
	}
	
	if (TTF_Init() != 0){
		std::cout << "There was a problem init TTF: " << SDL_GetError() << std::endl;
		return -1;
	}

	window = SDL_CreateWindow("Buttoneer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);

	if (!window){
		std::cout << "There was a problem creating the window: " << SDL_GetError() << std::endl;
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (!renderer){
		std::cout << "There was a problem creating the renderer: " << SDL_GetError() << std::endl;
		return -1;
	}

	return 0;
}

void Window::Render(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(TextManager::font);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Goodbye cruel world!" << std::endl;
}


