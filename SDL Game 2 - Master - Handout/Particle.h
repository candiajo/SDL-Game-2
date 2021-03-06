#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "Globals.h"
#include "Point.h"
#include "Timer.h"
#include "Module.h"
#include "Collider.h"
#include "ModuleCollisions.h"
#include "SDL\include\SDL.h"

class Particle : public Module
{
public:
	Particle(particle_info& particle);
	~Particle();

	bool Init();
	update_status Update();

private:
	fPoint position;
	Timer* life;
	SDL_Texture* particles_sheet;
	SDL_Rect particle_frame;
	fPoint speed;
};

#endif // __PARTICLE_H__