#include "../header/Global.hpp"
#include <memory>

bool running = true;
bool inMenu = true;
std::shared_ptr<Window> mainWindow = std::make_shared<Window>();
TextManager* UniVersalTextManager;
char currentInstruction = 'e';
