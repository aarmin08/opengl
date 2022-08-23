#include <iostream>
#include <memory>
#include "AnEntity.hpp"
#include "AComponent.hpp"
#include "Camera.hpp"
#include "Component.hpp"
#include "Box.hpp"
#include "Game.hpp"
#include "GLFW/glfw3.h"
#include "Utils/Utils.hpp"
#include "World.hpp"

int main(int args, char **argc) {
    std::cout << "Main entry" << std::endl;
    Window window{Window(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, "Gaming Amogus 900")};
    Utils::PerformLoading(&window);
	Camera* camera{ new Camera(-1.0,1.0,-1.0, 1.0)};	
    Renderer renderer{Renderer(&window, camera)};
    World *world{new World()};
	std::cout << "Created aaddcdecomponetn" << std::endl; 
	Utils::Log("Gaming", Utils::LogInfo::TEST_LOG);
	Game game{Game(&window, &renderer, world, 0.1, 0.1, 0.1)};

    world->Spawn<AnEntity>(10).addComponentToEntity<Box>(); 

    game.Start();
    while (game.isRunning()) {
        game.Update();
    }
    game.Dispose();

    return EXIT_SUCCESS;
}
