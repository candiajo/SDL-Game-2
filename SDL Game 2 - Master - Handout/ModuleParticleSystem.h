#ifndef __MODULEPARTICLESYSTEM_H__
#define __MODULEPARTICLESYSTEM_H__

#include<list>
#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include "Timer.h"
#include "Particle.h"

struct SDL_Texture;

class ModuleParticleSystem : public Module
{
public:
	ModuleParticleSystem();
	~ModuleParticleSystem();

	void CreateParticle(particle_info& particle);

	bool Init();
	update_status Update();

private:
	std::list<Particle*> particles;
};

#endif // __MODULEPARTICLESYSTEM_H__