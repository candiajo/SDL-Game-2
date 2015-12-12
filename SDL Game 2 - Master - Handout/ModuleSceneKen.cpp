#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the foreground (red ship) with
	// coordinates x,y,w,h from ken_stage.png

	// Pink Ship
	pink_ship.x = 8;
	pink_ship.y = 24;
	pink_ship.w = 522;
	pink_ship.h = 197;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({848, 208, 40, 40});
	flag.frames.push_back({848, 256, 40, 40});
	flag.frames.push_back({848, 304, 40, 40});
	flag.speed = 0.08f;

	// TODO 4: Setup Girl Animation from coordinates from ken_stage.png
	pink_girl.frames.push_back({ 624, 16, 32, 56 });
	pink_girl.frames.push_back({ 624, 80, 32, 56 });
	pink_girl.frames.push_back({ 624, 144, 32, 56 });
	pink_girl.speed = 0.08f;
}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();
	App->player2->Enable();

	App->collisions->AddCollider(App->player->collider);
	App->collisions->AddCollider(App->player2->collider);
	// TODO 0: trigger background music
	App->audio->PlayMusic(KEN_STAGE_MUSIC);


	
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// TODO 5: make sure the ship goes up and down

	// Draw everything --------------------------------------
	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	
	App->renderer->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->renderer->Blit(graphics, 0, yOffset, &pink_ship, 0.50f); // pink ship
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), .75f); // flag animation


	// TODO 3: Draw the ship. Be sure to tweak the speed.
	if (bajando)
	{
		yOffset += 0.2;
		if (yOffset > 10) bajando = false;
	}
	else
	{
		yOffset -= 0.2;
		if (yOffset <= 0) bajando = true;
	}

	// TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 192, yOffset + 104, &(pink_girl.GetCurrentFrame()), 0.50f); // pink girl

	App->renderer->Blit(graphics, 0, 170, &ground);
	

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module

	return UPDATE_CONTINUE;
}