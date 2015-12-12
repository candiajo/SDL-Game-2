#ifndef __MODULE_H__
#define __MODULE_H__

#include "Globals.h"
#include "Collider.h"
//class Collider;

class Module
{
public:

	Module(bool active = true) : active(active)
	{}

	~Module()
	{}

	virtual bool OnCollision(Collider* collider1, Collider* collider2)
	{
		collider1->listener->active = false;
		collider1->ToDelete = true;

		return true;
	};

	bool IsEnabled() const
	{
		return active;
	}

	 bool Enable()
	{
		if(active == false)
			return active = Start();

		return true;
	}

	 bool Disable()
	 {
		 if(active == true)
			 return active = !CleanUp();

		 return true;
	 }

	virtual bool Init() 
	{
		return true; 
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}

	Collider* collider = NULL;

private:
	bool active = true;
};

#endif // __MODULE_H__