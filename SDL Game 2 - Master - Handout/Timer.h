#ifndef __TIMER_H__
#define __TIMER_H__

#include "SDL\include\SDL.h"

class Timer
{
public:
	Timer(int life_time);
	~Timer();

	void StartTimer();
	bool InTime();

private:
	int start_time;
	int life_time;	// in milliseconds
};

#endif //__TIMER_H__