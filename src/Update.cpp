#include <SDL2/SDL_events.h>
#include "../header/Update.hpp"
#include "../header/Global.hpp"

void PollEvents(){
	SDL_Event e;
	while(SDL_PollEvent(&e) >= 1){
		switch (e.type) {
			case SDL_QUIT:
				running = false;
				break;
		}
	}
}

void Update(){
	while(running){
		PollEvents();
		mainWindow->Render();
	}
}
