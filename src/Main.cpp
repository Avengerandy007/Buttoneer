#include "../header/window.hpp"
#include "../header/Update.hpp"
#include "../header/Global.hpp"
#include <iostream>

int main(){
	std::cout << "Hello world" << std::endl;
	if (mainWindow->Setup() != 0) return -1;
	Update();
}
