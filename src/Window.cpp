#include "Window.hpp"
#include "Utils/Utils.hpp"
#include <iostream>

Window::Window(int x, int y, int w, int h, const char *title) {
    this->height = h;
    this->width = w;
    this->x = x;
    this->y = y;
    this->title = title;
}

Window::Window() {}

void Window::Load(int flags) {
    std::cout << "Loading window" << std::endl;
    window = SDL_CreateWindow(title, x, y, width, height, flags | SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
    if (!window) {
		Utils::Log("The window was not created.", Utils::LogInfo::TEST_FATAL);
	}
    std::cout << "made window" << std::endl;
}

void Window::Clean() {
    SDL_DestroyWindow(window);
}

void Window::SwapBuffers() {
    SDL_GL_SwapWindow(window);
}
