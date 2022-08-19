#include "Game.hpp" 
#include "texturemanager.hpp"
#include "collisioncheck.hpp"
#include "rb.hpp"
#include <iostream>

Game::Game() {}; 
Game::~Game() {}; 

SDL_Texture* texture {nullptr}; 
SDL_Rect rect {0,0,32,32}; 

std::vector<Collider> colliders {}; 

Manager* manager = new Manager(); 
Entity& entity {manager->addEntity()};
Entity& wall {manager->addEntity()};

std::vector<Collider*> Game::colliders; 

CollisionCheck* collisionCheck;

Vector2d* direction = new Vector2d(20,20); 

SDL_Window* Game::window; 
SDL_Renderer* Game::renderer;
SDL_Event Game::event;

float Game::count {1}; 
void Game::initGame(const char *title, int xpos, int ypos, int w, int h, bool fullscreen) {
	int flags = 0; 
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, xpos, ypos, w, h, flags); 
		if (window) {
			std::cout << "Window made" << std::endl; 
		}

		renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED); 
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
			std::cout << "Created Renderer!" << std::endl; 
		}

		running = true; 
	} else {
		running = false; 
	}
	
	collisionCheck = new CollisionCheck(); 

	entity.addComponent<TransformComponent>(10.0,10.0,32.0,32.0, 1); 
	entity.addComponent<Collider>("entity"); 
	entity.addComponent<SpriteComponent>("assets/c.png");
	entity.addComponent<RigidBody>();

	wall.addComponent<TransformComponent>(10.0,1000.0,32,32,1); 
	wall.addComponent<Collider>("gaming");
	wall.addComponent<SpriteComponent>("assets/c.png");

	std::cout << "Reached" << std::endl;	
	count++; 
	std::cout << "Texture made" << std::endl;
}

void Game::renderGame() {
	SDL_RenderClear(renderer);
	entity.getComponent<SpriteComponent>().draw();
	wall.getComponent<SpriteComponent>().draw();
	TextureManager::Load(texture, rect);
	SDL_RenderPresent(renderer); 
}

void Game::handleEvents() {
	SDL_PollEvent(&event); 
	switch (event.type) {
		case SDL_QUIT: 
			running = false;
		case SDL_KEYDOWN:
			entity.getComponent<RigidBody>().AddForce(direction); 
	}

}
int i = 0; 
void Game::handleUpdate() {	
	for (auto c : colliders) {
		CollisionCheck::collision(entity.getComponent<Collider>(), *c);
	}


	i++;

	if (i >= 10 && i<= 20)
	{
	}

	manager->update(); 

}

void Game::cleanGame() {
	SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer); 

	SDL_Quit(); 
}
