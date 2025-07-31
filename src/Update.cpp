#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <memory>
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include "../header/Update.hpp"
#include "../header/TextManager.hpp"
#include "../header/Global.hpp"

auto timerStart = std::chrono::system_clock::now();

void PollEvents(){
	SDL_Event e;
	while(SDL_PollEvent(&e) >= 1){
		switch (e.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (inMenu){
					//Start the game
					if (e.key.keysym.sym == SDLK_s){
						delete UniVersalTextManager;
						UniVersalTextManager = new TextManager();
						inMenu = false;
					}
					break;
				}
				char help = currentInstruction;
				if (e.key.keysym.sym == SDL_GetKeyFromName(&help)){
					currentInstruction = TextManager::GetRandomChar();
					std::ostringstream stream;
					stream << "Please type: " << currentInstruction; 
					UniVersalTextManager->CreateText(stream.str());
					timerStart = std::chrono::system_clock::now();
				}else{
					UniVersalTextManager->CreateError("Dang, you don't know your keys");
					timerStart = std::chrono::system_clock::now();
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
		UniVersalTextManager->RenderErrors();
		SDL_RenderPresent(mainWindow->renderer);
		const auto timerNow = std::chrono::system_clock::now();
		const auto timerDiff = timerNow - timerStart;
		if (timerDiff.count() > 2e9 && !inMenu){
			UniVersalTextManager->CreateError("Times is up");
			timerStart = std::chrono::system_clock::now();

		}
		SDL_Delay(2);
	}
}
