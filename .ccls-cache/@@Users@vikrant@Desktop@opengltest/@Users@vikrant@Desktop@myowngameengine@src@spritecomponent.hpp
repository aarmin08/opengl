#pragma once 

#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "texturemanager.hpp"
#include "components.hpp"
#include "SDL2/SDL.h"

class SpriteComponent :  public Component {
	private :
		SDL_Texture* texture; 
		SDL_Rect dest; 
		TransformComponent* position; 
		
	public :
		SpriteComponent() = default; 
		SpriteComponent(const char* path) {
			texture = TextureManager::loadTexture(path); 
		}

		~SpriteComponent() {
			SDL_DestroyTexture(texture); 
		}
	
		void update() override {
			position = &entity->getComponent<TransformComponent>();
			dest.x = position->position->_x; 
			dest.y = position->position->_y; 
			dest.w = position->width; 
			dest.h = position->height; 	
		}

		void draw() override {
			TextureManager::Load(texture, dest); 
		} 
};

#endif
