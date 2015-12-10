#include "Particle.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"

Particle::Particle(particle_info& particle)
{
	position = particle.position;
	speed = particle.speed;
	vida = particle.vida;
	texture = particle.texture;
}

Particle::~Particle()
{}

bool Particle::Init()
{}

update_status Particle::Update()
{
	position += speed;

	App->renderer->Blit(graphics, 0, 0, &texture, 0.75f);

}