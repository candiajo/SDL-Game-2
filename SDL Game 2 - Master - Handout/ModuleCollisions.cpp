#include "ModuleCollisions.h"
#include "Collider.h"


ModuleCollisions::ModuleCollisions()
{}

ModuleCollisions::~ModuleCollisions()
{}

update_status ModuleCollisions::Update()
{
	DetectCollisions();

	return UPDATE_CONTINUE;
}

update_status ModuleCollisions::PostUpdate()
{
	for (auto it = colliders.begin(); it != colliders.end();)
	{
		if ((*it)->ToDelete)
			it = colliders.erase(it);
		else
			it++;
	}

	return UPDATE_CONTINUE;
}

void ModuleCollisions::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
}

void ModuleCollisions::RemoveCollider(Collider* collider)
{
	colliders.remove(collider);
}

void ModuleCollisions::DetectCollisions()
{
	SDL_Rect nada;
	int tam = colliders.size();

	if (colliders.size() == 3)
	{
		int stop;
		stop = 2;
	}
	if (colliders.size() > 1)
	{
		auto primero = colliders.begin();
		auto penultimo = colliders.end();
		penultimo--; penultimo--;
		auto ultimo = colliders.end();
		ultimo--;
		auto fin = colliders.end();

		for (auto it1 = primero; it1 != ultimo; it1++)
		{
			auto siguiente = it1;
			siguiente++;

			for (auto it2 = siguiente; it2 != fin; it2++)
			{
				
				if (SDL_IntersectRect(&(*it1)->area, &(*it2)->area, &nada))
				{
					(*it1)->listener->OnCollision((*it1), (*it2));
					(*it2)->listener->OnCollision((*it2), (*it1));
				}
			}
		}
	}
}

/*
for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
ret = (*it)->Init(); // we init everything, even if not anabled
*/
