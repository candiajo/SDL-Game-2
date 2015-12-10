#include "ModuleParticleSystem.h"

ModuleParticleSystem::ModuleParticleSystem()
{}

ModuleParticleSystem::~ModuleParticleSystem()
{}

bool ModuleParticleSystem::Init()
{}

update_status ModuleParticleSystem::Update()
{
	for (auto& it : particles)
		it->Update();
}

void ModuleParticleSystem::CreateParticle(particle_info& particle)
{
	particles.push_back(new Particle(particle));
}