#include "Collider.h"

Collider::Collider(Module* listener, int x, int y, int w, int h)
{
	this->listener = listener;

	this->area.x = x;
	this->area.y = y;
	this->area.w = w;
	this->area.h = h;
}

Collider::~Collider()
{}