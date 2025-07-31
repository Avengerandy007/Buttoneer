#include "../header/DayManager.hpp"

std::vector<Day> Day::days;

Day::Day(){
	days.push_back(*this);
}
