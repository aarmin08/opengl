#pragma once

#include "Rendering/Renderer.hpp"
#include "Camera.hpp"
#include "Entity.hpp"
#include "World.hpp"
#include <boost/any.hpp>

class Game {
private :
    Window *window{new Window()};
    Renderer *renderer{new Renderer()};

    World *world{new World()};

    static SDL_Event event;


	bool isInSandboxMode; 
    bool running;

    float r, g, b;
public :
    Game(Window *win, Renderer *renderer, World *world, float r, float b, float g) {
        this->world = world;
        window = win;
        this->renderer = renderer;
        this->r = r;
        this->b = b;
        this->g = g;
    }
	static Camera* camera;

    bool isRunning() { return running; }
	bool isSandbox() { return isInSandboxMode; }

    void Start(); // TODO
    void Update();
    void Dispose();
    void Render();
}; 
