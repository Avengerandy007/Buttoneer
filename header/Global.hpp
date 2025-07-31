#pragma once
#include "TextManager.hpp"
#include "window.hpp"
#include <memory>
#include <vector>

extern bool running;
extern std::shared_ptr<Window> mainWindow;
extern TextManager* UniVersalTextManager;
extern char currentInstruction;

template<typename T>
int FindIndexOf(T* var, std::vector<T*>* list){
	int i = 0;
	for (T* obj : *list){
		if (obj == var){
			return i;
		}
		i++;
	}
	return -1;
}
