#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "Globals.h"

class Module;

class Collider
{
public:
	Collider(Module* listener, int x, int y, int w, int h);
	~Collider();

	SDL_Rect area;
	Module* listener = nullptr;
	bool ToDelete = false;
};
#endif // __COLLIDER_H__