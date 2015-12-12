#include "Particle.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"

Particle::Particle(particle_info& particle)
{
	position = particle.position;
	speed = particle.speed;
	life = new Timer(particle.life_time);
	particle_frame = particle.particle_frame;
	particles_sheet = particle.particles_sheet;
	life->StartTimer();
}

Particle::~Particle()
{
	delete (life);
}

bool Particle::Init()
{
	return true;
}

update_status Particle::Update()
{
	if (life->InTime())
	{
		position += speed;

		App->renderer->Blit(particles_sheet, position.x, position.y, &particle_frame, 0.75f);
	}
	else
	{
		// marcar para borrar
	}
	return UPDATE_CONTINUE;
}