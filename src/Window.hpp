#pragma once

#include "SDL2/SDL.h"

class Window {
public :
    const char *title;
    int width, height, x, y;
    SDL_Window *window{};

    Window();

    Window(int w, int h, int x, int y, const char *title);

    void Load(int flags);

    void Clean();

    void SwapBuffers();
};  
