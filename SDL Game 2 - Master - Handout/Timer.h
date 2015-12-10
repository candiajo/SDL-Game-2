#ifndef __TIMER_H__
#define __TIMER_H__

#include "SDL\include\SDL.h"

class Timer
{
public:
	Timer();
	~Timer();

	void StartTimer();
	int Time();

private:
	int start_time;
};

Timer::Timer()
{}

Timer::~Timer()
{}

void Timer::StartTimer()
{
	start_time = SDL_GetTicks();
}

int Timer::Time()
{
	return SDL_GetTicks() - start_time;
}

#endif //__TIMER_H__