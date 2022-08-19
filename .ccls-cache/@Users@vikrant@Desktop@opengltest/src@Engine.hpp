#pragma once 

#include "SDL2/SDL.h"
#include "Manager.hpp"

#ifndef ENGINE_HPP 
#define ENGINE_HPP

class Engine {
	private : 
		bool running; 
	public : 
		void init(const char* title, int xpos, int ypos, int w, int h);
		void whileRunning(); // check for events here and render
		void clean();
		void update();
		void render(); 

		bool isRunning() {return running; }

		static SDL_Window* window; 
		static SDL_Event event; 
		static Manager* manager; 
};

#endif 
