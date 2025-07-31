#include "../header/Global.hpp"
#include <memory>
#include <sstream>

bool running = true;
bool inMenu = true;
std::shared_ptr<Window> mainWindow = std::make_shared<Window>();
TextManager* UniVersalTextManager;
char currentInstruction = 'e';

void CreateInstruction(){
	currentInstruction = TextManager::GetRandomChar();
	std::ostringstream stream;
	stream << "Please type: " << currentInstruction; 
	UniVersalTextManager->CreateText(stream.str());
}
