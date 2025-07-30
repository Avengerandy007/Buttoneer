#include <SDL2/SDL_events.h>
#include <memory>
#include <string>
#include "../header/Update.hpp"
#include "../header/TextManager.hpp"
#include "../header/Global.hpp"

void PollEvents(){
	SDL_Event e;
	while(SDL_PollEvent(&e) >= 1){
		switch (e.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				testTextManager.CreateText("Hello world!");
				testTextManager.MoveTextUp();
				break;
		}
	}
}

void Update(){
	while(running){
		PollEvents();
		mainWindow->Render();
		for(TextLine* line : testTextManager.lines){
			line->Render();
		}
		SDL_RenderPresent(mainWindow->renderer);
	}
}
