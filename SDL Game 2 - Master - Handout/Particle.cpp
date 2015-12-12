#include "Particle.h"
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

	collider = new Collider(this, position.x, position.y, particle_frame.w, particle_frame.h);
	App->collisions->AddCollider(collider);
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
	if (life->InTime() && IsEnabled())
	{
		position += speed;
		collider->area.x = position.x;
		collider->area.y = position.y;

		App->renderer->Blit(particles_sheet, position.x, position.y, &particle_frame, 0.75f);
	}
	else
	{
		// marcar para borrar
		
	}
	return UPDATE_CONTINUE;
}