#include "Game.hpp"
#include "SDL2/SDL_opengl.h"
#include "glm/fwd.hpp"

#define GLFW_INCLUDE_NONE

#include "SDL2/SDL.h"
#include "GLFW/glfw3.h"
#include <iostream>

Camera* Game::camera; 
SDL_Event Game::event;

void Game::Start() {
	camera = renderer->getCamera(); 
    renderer->RendererStart(r, g, b);
    running = true;
}

void Game::Update() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
		
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
	
			}
		}

        for (auto &entity: world->entities) {
            entity->Update();
        }
        /* std::cout << glGetError() << std::endl; */
        Render();
    }
}

void Game::Dispose() {
    window->Clean();
    glfwTerminate();
    SDL_Quit();
}

void Game::Render() {
    renderer->Render(world);
}
