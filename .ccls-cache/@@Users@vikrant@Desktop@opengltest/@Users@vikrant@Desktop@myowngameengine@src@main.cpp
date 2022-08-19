#include <iostream> 
#include "Game.hpp"


int main() {
	const int FPS = 60; 
	const int FRAMEDELAY = 1000/FPS; 
	std::cout << "Running game" << std::endl; 
	Game* game = new Game(); 

	Uint32 frameStart{0}; 
	int frameTime; 

	game->initGame("Trolling", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 650, false); 
	
	while (game->isRunning()) {
		game->renderGame();
		game->handleEvents();
		game->handleUpdate(); 

		frameTime = SDL_GetTicks() - frameStart; 
		if (FRAMEDELAY > frameTime) {
			SDL_Delay(FRAMEDELAY-frameTime); 
		}
	};

	game->cleanGame();

	return EXIT_SUCCESS; 
}
