#pragma once 

#include "SDL2/SDL.h"

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

class TextureManager {
	public : 
		static SDL_Texture* loadTexture(const char* path); 
		static void Load(SDL_Texture* texture, SDL_Rect dest); 
};

#endif 
