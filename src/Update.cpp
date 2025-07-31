#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
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
				char help = currentInstruction;
				if (e.key.keysym.sym == SDL_GetKeyFromName(&help)){
					currentInstruction = TextManager::GetRandomChar();
					std::ostringstream stream;
					stream << "Please type: " << currentInstruction; 
					UniVersalTextManager->CreateText(stream.str());
				}else{
					UniVersalTextManager->CreateError("Cmon dude just press the dang button, it ain't that hard");
				}
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
