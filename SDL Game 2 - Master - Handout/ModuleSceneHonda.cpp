#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// ceiling
	ceiling.x = 92;
	ceiling.y = 7;
	ceiling.w = 764;
	ceiling.h = 46;
	
	// Background / wall
	background.x = 217;
	background.y = 176;
	background.w = 768;
	background.h = 128;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading Honda scene");

	graphics = App->textures->Load("honda_stage.png");

	App->player->Enable();

	App->audio->PlayMusic(HONDA_STAGE_MUSIC);

	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading Honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	App->renderer->Blit(graphics, 0, 46, &background, 0.65f); // wall
	App->renderer->Blit(graphics, 0, 0, &ceiling, 0.75f); // wall
	App->renderer->Blit(graphics, 0, 170, &ground, 0.75f);

	return UPDATE_CONTINUE;
}