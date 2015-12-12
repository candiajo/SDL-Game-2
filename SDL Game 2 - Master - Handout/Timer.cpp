#include "Timer.h"

Timer::Timer(int life_time)
{
	this->life_time = life_time;
}

Timer::~Timer()
{}

void Timer::StartTimer()
{
	start_time = SDL_GetTicks();
}

bool Timer::InTime()
{
	int elapsed_time = (SDL_GetTicks() - start_time);

	if (elapsed_time > life_time)
		return false;
	else
		return true;
}