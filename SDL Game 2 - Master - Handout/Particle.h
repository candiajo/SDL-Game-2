#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "Globals.h"
#include "Point.h"
#include "Timer.h"
#include "SDL\include\SDL.h"

class Particle
{
public:
	Particle(particle_info& particle);
	~Particle();

	bool Init();
	update_status Update();

private:
	fPoint position;
	Timer vida;
	SDL_Texture* texture;
	fPoint speed;
};

#endif // __PARTICLE_H__