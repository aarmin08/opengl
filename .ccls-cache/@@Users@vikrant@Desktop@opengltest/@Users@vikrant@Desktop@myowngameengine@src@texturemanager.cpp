#include "texturemanager.hpp"
#include "SDL2/SDL.h"
#include "Game.hpp"
#include "SDL2/SDL_image.h"

SDL_Texture* TextureManager::loadTexture(const char* path) {
	SDL_Surface* tmp = IMG_Load(path); 
	SDL_Texture* texture = NULL; 
	if (tmp) {
		texture = SDL_CreateTextureFromSurface(Game::renderer, tmp); 
		SDL_FreeSurface(tmp);
	}
	return texture; 
}

void TextureManager::Load(SDL_Texture *texture, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, texture, NULL, &dest); 
}
