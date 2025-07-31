#include "../header/Global.hpp"
#include <cstdint>
#include <memory>
#include <sstream>

bool running = true;
bool inMenu = true;
bool gameOver = false;
uint32_t score = 0;
std::shared_ptr<Window> mainWindow = std::make_shared<Window>();
TextManager* UniVersalTextManager;
char currentInstruction = 'e';

void CreateInstruction(){
	currentInstruction = TextManager::GetRandomChar();
	std::ostringstream stream;
	stream << "Please type: " << currentInstruction; 
	UniVersalTextManager->CreateText(stream.str());
}
