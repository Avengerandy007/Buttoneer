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

void CheckErrors(){
	if (UniVersalTextManager->errorLines.size() > 3){
		gameOver = true;
		delete UniVersalTextManager;
		UniVersalTextManager = new TextManager();
		std::stringstream stream;
		stream << "Game Over";
		UniVersalTextManager->CreateText(stream.str());
		stream.str("");
		stream << "Final Score: " << score;
		UniVersalTextManager->CreateText(stream.str());
		score = 0;
	}
}

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
						timerStart = std::chrono::system_clock::now();
						CreateInstruction();
					}
					break;
				}else if (gameOver){
					gameOver = false;
					delete UniVersalTextManager;
					UniVersalTextManager = new TextManager;
					timerStart = std::chrono::system_clock::now();
					CreateInstruction();
					break;
				}
				if (e.key.keysym.sym == SDL_GetKeyFromName(&currentInstruction) && !gameOver){
					CreateInstruction();
					score++;
					timerStart = std::chrono::system_clock::now();
				}else{
					if(gameOver) break;
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
		CheckErrors();
		const auto timerNow = std::chrono::system_clock::now();
		const auto timerDiff = timerNow - timerStart;
		if (timerDiff.count() > 2e9 && !inMenu && !gameOver){
			UniVersalTextManager->CreateError("Waited for too long");
			timerStart = std::chrono::system_clock::now();

		}
		SDL_Delay(2);
	}
}
