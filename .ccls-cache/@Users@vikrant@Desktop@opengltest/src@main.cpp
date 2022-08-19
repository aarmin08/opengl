#include <iostream> 
#include "Engine.hpp"

int main() {
	std::cout << "Gaing" << std::endl; 
	Engine* engine {new Engine()}; 
	
	engine->init("GTTT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480); 
	while (engine->isRunning()) {
		engine->whileRunning(); 
	}

	engine->clean(); 

	return EXIT_SUCCESS; 
}
