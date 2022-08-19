#pragma once 

#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include <vector>

class Collider; 

class Game {
	private : 
		bool running;
	public :
		Game(); 
		~Game(); 
		
		void initGame(const char* title, int xpos, int ypos, int w, int h, bool fullscreen); 
		void handleUpdate(); 
		void renderGame(); 
		void handleEvents();
		
		void cleanGame(); 

		bool isRunning() { return running; }
		
		static float count;

		static SDL_Window* window; 
		static SDL_Event event; 
		static SDL_Renderer* renderer;
		static std::vector<Collider*> colliders; 
};

#endif 
