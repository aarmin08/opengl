#pragma once 

#ifndef COLLIDER_HPP
#define COLLIDER_HPP 

#include "Game.hpp"
#include "components.hpp"

class Collider : public Component {
	public :
		TransformComponent* transform; 
		SDL_Rect collider;
		const char* tag;

		bool isColliding = false; 

		Collider() = default;
		Collider(const char* tag) {
			this->tag = tag; 
		}

		void init() override {
			if (!entity->hasComponent<TransformComponent>()) {
				entity->addComponent<TransformComponent>(); 
			}
			transform = &entity->getComponent<TransformComponent>();
			Game::colliders.push_back(this); 
		}; 

		bool CompareTag(const char* tag) {
			if (this->tag == tag) {
				return true; 
			} else {
				return false; 
			}
		}
		
		void update() override {
			collider.x = transform->position->_x; 
			collider.y = transform->position->_y; 
			collider.w = transform->width * transform->scale; 
			collider.h = transform->height * transform->scale; 
		}; 
}; 

#endif
