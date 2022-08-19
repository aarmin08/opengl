#pragma once

#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "components.hpp"
#include "vector2.hpp"
#include "SDL2/SDL.h"

class TransformComponent : public Component {
	public : 
		Vector2d* position = new Vector2d(0,0);
		int width = 32; 
		int height = 32; 

		int scale = 1; 

		TransformComponent() {
			position->Zero(); 
		}; 

		TransformComponent(float x, float y, float w, int h, int scale) {
			position->setPos(x,y);
			width = w; 
			height = h; 
			this->scale = scale; 
		}	
};

#endif
