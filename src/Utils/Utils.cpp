#include "Utils.hpp"
#include <GL/glew.h>
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL.h"

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"

#include <iostream>

const char *Utils::vertexSrc = "#version 330 core\n"
                               "layout (location = 0) in vec3 aPos;\n"
                               "out vec3 vPos;\n"
                               "uniform mat4 u_viewProjection;\n"
                               "void main()\n"
                               "{\n"
                               "	vPos = aPos;\n"
                               "   gl_Position = u_viewProjection * vec4(aPos, 1.0);\n"
                               "}\n\0";
const char *Utils::fragmentSource = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "in vec3 vPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = vec4(0.3f,0.3f,1.0f, 1.0f);\n"
                                    "}\n\0";

void Utils::PerformLoading(Window *window) {
// doesn't help
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed" << std::endl;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GLattr::SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    glfwInit();
    window->Load(SDL_WINDOW_OPENGL);
    SDL_GLContext Context = SDL_GL_CreateContext(window->window);
    SDL_GL_MakeCurrent(window->window, Context);
    /* if (!gladLoadGL()) { */
    /* 	std::cerr << "Failed to initialize the OpenGL context." << std::endl; */
    /* 	std::cout << SDL_GetError() << std::endl; */
    /* 	exit(1); */
    /* } */
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
		Log("Error", TEST_FATAL); 
	}
}

template<typename T>
void Utils::Log(T t, LogInfo info) {
	switch (info) {
		case TEST_ERR:
			std::cout << "ERROR: " << t << std::endl; 
			break; 
		case TEST_FATAL: 
			std::cout << "FATAL ERROR: " << t << std::endl;
			exit(1); 
			break;
		case TEST_LOG: 
			std::cout << "LOG: " << t << std::endl; 
			break; 
		case TEST_WARNING: 
			std::cout << "WARNING! " << t << std::endl; 
			break; 
		default: break; 
	}; 

};
