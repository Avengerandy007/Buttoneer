#include "../header/Global.hpp"
#include <memory>

bool running = true;
std::shared_ptr<Window> mainWindow = std::make_shared<Window>();
//std::shared_ptr<TextManager> testTextManager = std::make_shared<TextManager>();
TextManager testTextManager;
