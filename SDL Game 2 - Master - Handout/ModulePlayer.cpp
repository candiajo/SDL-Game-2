#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

	// idle animation (arcade sprite sheet)
	idle.frames.push_back({7, 14, 60, 90});
	idle.frames.push_back({95, 15, 60, 89});
	idle.frames.push_back({184, 14, 60, 90});
	idle.frames.push_back({276, 11, 60, 93});
	idle.frames.push_back({366, 12, 60, 92});
	idle.speed = 0.2f;
	
	// walk backward animation (arcade sprite sheet)
	backward.frames.push_back({542, 131, 61, 87});
	backward.frames.push_back({628, 129, 59, 90});
	backward.frames.push_back({713, 128, 57, 90});
	backward.frames.push_back({797, 127, 57, 90});
	backward.frames.push_back({883, 128, 58, 91});
	backward.frames.push_back({974, 129, 57, 89});
	backward.speed = 0.1f;

	// TODO 8: setup the walk forward animation from ryu4.png
	forward.frames.push_back({ 0, 127, 68, 93 });
	forward.frames.push_back({ 78, 127, 68, 93 });
	forward.frames.push_back({ 161, 127, 68, 93 });
	forward.frames.push_back({ 251, 127, 73, 93 });
	forward.frames.push_back({ 341, 127, 68, 93 });
	forward.frames.push_back({ 419, 127, 68, 93 });
	forward.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("ryu4.png"); // arcade version
	position.x = 30;
	position.y = 120;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		ryu_status = PLAYER_BACKWARD;
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		ryu_status = PLAYER_FORWARD;
	else
		ryu_status = PLAYER_IDLE;

	switch (ryu_status)
	{
	case PLAYER_IDLE:
		App->renderer->Blit(graphics, position.x, position.y, &(idle.GetCurrentFrame()), .075f);
		break;
	case PLAYER_FORWARD:
		position.x++;
		App->renderer->Blit(graphics, position.x, position.y, &(forward.GetCurrentFrame()), .075f);
		break;
	case PLAYER_BACKWARD:
		position.x--;
		App->renderer->Blit(graphics, position.x, position.y, &(backward.GetCurrentFrame()), .075f);
		break;
	}

	return UPDATE_CONTINUE;
}