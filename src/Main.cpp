#include "../header/window.hpp"
#include "../header/TextManager.hpp"
#include "../header/Update.hpp"
#include "../header/Global.hpp"
#include <iostream>
#include <sstream>

void InitMenu(){
	UniVersalTextManager = new TextManager();
	UniVersalTextManager->Start();
	std::ostringstream stream;
	stream << "Buttoneer"; 
	UniVersalTextManager->CreateText(stream.str());
	stream.str(std::string());
	stream << "Press 'a' to view about page.";
	UniVersalTextManager->CreateText(stream.str());
	stream.str(std::string());
	stream << "Press 's' to start the game.";
	UniVersalTextManager->CreateText(stream.str());
}

int main(){
	std::cout << "Hello world!" << std::endl;
	if (mainWindow->Setup() != 0) return -1;
	InitMenu();
	Update();
	delete UniVersalTextManager;
}
