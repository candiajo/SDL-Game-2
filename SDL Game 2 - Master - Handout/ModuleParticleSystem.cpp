#include "ModuleParticleSystem.h"
#include "Application.h"
#include "ModuleTextures.h"

ModuleParticleSystem::ModuleParticleSystem()
{}

ModuleParticleSystem::~ModuleParticleSystem()
{}

bool ModuleParticleSystem::Init()
{
	return true;
}

bool ModuleParticleSystem::Start()
{
	LOG("Loading player");

	particles_sheet = App->textures->Load(RYU_SPRITES);
	return true;
}

update_status ModuleParticleSystem::Update()
{
	for (auto& it : particles)
		it->Update();
		
	return UPDATE_CONTINUE;
}

// Unload assets
bool ModuleParticleSystem::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(particles_sheet);

	for (auto& it : particles)
		delete(it);

	return true;
}

void ModuleParticleSystem::CreateParticle(particle_info& particle)
{
	particle.particles_sheet = particles_sheet;
	particles.push_back(new Particle(particle));
}