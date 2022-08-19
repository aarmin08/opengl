#pragma once 

#include "collider.hpp"

class CollisionCheck {
	public :
		static bool AABB(SDL_Rect a, SDL_Rect b);
		static bool collision(Collider a, Collider b);
}; 
