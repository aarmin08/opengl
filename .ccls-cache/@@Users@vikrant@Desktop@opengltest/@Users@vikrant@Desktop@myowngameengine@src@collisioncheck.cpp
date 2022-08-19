#include "collisioncheck.hpp"
#include "rb.hpp"
#include <iostream>
bool CollisionCheck::AABB(SDL_Rect a, SDL_Rect b) {
	// AABB check
	/* std::cout << "AA BB" <<std::endl; */ 
	if (
			a.x + a.w >= b.x &&
			b.x + b.w >= a.x &&
			a.y + a.h >= b.y &&
			b.y + b.h >= a.y
		) {
		return true;  
	} else {
		return false; 
	}
}

bool CollisionCheck::collision(Collider a, Collider b) {
	/* std::cout << "Checking " << std::endl; */ 
	if (AABB(a.collider, b.collider) && a.tag != b.tag) {
		b.isColliding = true; 
		a.isColliding = true;
		
		if (a.entity->hasComponent<RigidBody>() && b.entity->hasComponent<RigidBody>()) {
			a.entity->getComponent<RigidBody>().isColliding = true; 
			b.entity->getComponent<RigidBody>().isColliding = true; 
		} else if (a.entity->hasComponent<RigidBody>() && !b.entity->hasComponent<RigidBody>()) {
			a.entity->getComponent<RigidBody>().isColliding = true; 
		} else if (b.entity->hasComponent<RigidBody>() && a.entity->hasComponent<RigidBody>()) {
			b.entity->getComponent<RigidBody>().isColliding = true; 
		}
		return true; 
	} else {
		if (a.entity->hasComponent<RigidBody>() && b.entity->hasComponent<RigidBody>()) {
			a.entity->getComponent<RigidBody>().isColliding = false; 
			b.entity->getComponent<RigidBody>().isColliding = false; 
		} else if (a.entity->hasComponent<RigidBody>() && !b.entity->hasComponent<RigidBody>()) {
			a.entity->getComponent<RigidBody>().isColliding = false; 
		} else if (b.entity->hasComponent<RigidBody>() && a.entity->hasComponent<RigidBody>()) {
			b.entity->getComponent<RigidBody>().isColliding = false; 
		}
		return false; 
	}
}
