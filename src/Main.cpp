#include "../header/window.hpp"
#include "../header/TextManager.hpp"
#include "../header/Update.hpp"
#include "../header/Global.hpp"
#include <iostream>
#include <sstream>

int main(){
	std::cout << "Hello world!" << std::endl;
	if (mainWindow->Setup() != 0) return -1;
	UniVersalTextManager = new TextManager();
	
	UniVersalTextManager->Start();
	std::ostringstream stream;
	stream << "Please type: " << currentInstruction; 
	UniVersalTextManager->CreateText(stream.str());

	Update();
	delete UniVersalTextManager;
}
