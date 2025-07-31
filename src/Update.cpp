#include <SDL2/SDL_events.h>
#include <memory>
#include <string>
#include <sstream>
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
				std::ostringstream stream;
				stream << "Please type: " << TextManager::GetRandomChar();
				UniVersalTextManager->CreateText(stream.str());
				UniVersalTextManager->MoveTextUp();
				break;
		}
	}
}

void Update(){
	while(running){
		PollEvents();
		mainWindow->Render();
		UniVersalTextManager->Render();
		SDL_RenderPresent(mainWindow->renderer);
	}
}
