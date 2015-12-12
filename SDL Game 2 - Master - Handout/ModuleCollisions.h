#ifndef __MODULECOLLISIONS_H__
#define __MODULECOLLISIONS_H__

#include <list>
#include "Module.h"
#include "Globals.h"
#include "Collider.h"


class ModuleCollisions : public Module
{
public:
	ModuleCollisions();
	~ModuleCollisions();

	update_status Update();
	update_status PostUpdate();

	void AddCollider(Collider* collider);
	void RemoveCollider(Collider* collider);

	void DetectCollisions();

private:
	std::list<Collider*> colliders;

};

#endif // __MODULECOLLISIONS_H__