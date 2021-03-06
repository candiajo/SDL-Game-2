#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"
#include "Collider.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true, int x = 100);
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation backward;
	Animation forward;
	iPoint position;
	player_status ryu_status = PLAYER_IDLE;
};

#endif // __MODULEPLAYER_H__