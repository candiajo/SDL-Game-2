#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL/include/SDL_rect.h"
#include "Point.h"

struct SDL_Texture;

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

struct particle_info
{
	fPoint position;
	int life_time;
	SDL_Texture* particles_sheet;
	SDL_Rect particle_frame;
	fPoint speed;
};

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum player_status
{
	PLAYER_IDLE,
	PLAYER_FORWARD,
	PLAYER_BACKWARD
};

// Deletes a buffer
#define RELEASE( x ) \
    {\
       if( x != nullptr )\
       {\
         delete x;\
	     x = nullptr;\
       }\
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{\
       if( x != nullptr )\
       {\
           delete[] x;\
	       x = nullptr;\
		 }\
	 }

// Configuration -----------
#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 224
#define SCREEN_SIZE 2
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Super Awesome Game"
#define KEN_STAGE_MUSIC "ken.ogg"
#define HONDA_STAGE_MUSIC "honda.ogg"
#define RYU_SPRITES "ryu.png"

#endif //__GLOBALS_H__