#include "Engine.hpp"
#include "SDL2/SDL_opengl.h"
#include "UserEngine.hpp"
#include <iostream>

SDL_Window* Engine::window {nullptr};
SDL_Event Engine::event;

Manager* Engine::manager {nullptr};

UserEngine* engine; 
void Engine::init(const char* title, int x, int y, int w, int h) {
	int flags = SDL_WINDOW_OPENGL; 

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		std::cout << "Failed" << std::endl; 
	}

	window = SDL_CreateWindow(title, x,  y, w,  h, flags); 
	if (!window) {
		std::cout << "Window not created" << std::endl; 
	}
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2); 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	manager = new Manager(); 
	engine = new UserEngine();
	engine->SetManager(manager); 
	SDL_GLContext Context = SDL_GL_CreateContext(window);
	glClearColor(1.f,0.f,1.f,0.f);
	glViewport(x, y, w, h);
	std::cout << "Gaming gaming gaming gaming gaming" << std::endl; 

	engine->Start();
	running = true; 
}

void Engine::whileRunning() {
	while (SDL_PollEvent(&event) != 0) {	
		switch (event.type) {
			case SDL_QUIT: 
				running = false; 
		}
		render();
	}
	update();
}

void Engine::render() {
		glClear(GL_COLOR_BUFFER_BIT);
		engine->Draw(); 
		SDL_GL_SwapWindow(window); 
}

void Engine::update() {
	engine->Update(); 
}

void Engine::clean() {
	SDL_DestroyWindow(window) ;
	SDL_Quit(); 
}
