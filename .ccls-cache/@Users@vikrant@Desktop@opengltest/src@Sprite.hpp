#pragma once 

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Component.hpp"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

const char* vertexShader = "version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0)"
"}\0";


const char* fragShader = ""; 

class Sprite : public Component {
	private :
		int w,h,n; 
		const char* p; 
	public :
		Sprite() {}; 	
		Sprite(const char* p, int w, int h, int n) {
			this->p = p; 
			this->w = w; 
			this->h = h; 
			this->n = n; 
		}; 

		void Start() override {
			glfwInit();
			std::cout << "Started" << std::endl; 
		}

		void Update() override {
			std::cout << "update" << std::endl; 
		}
		void Draw() override {
			
		}

		void Clean() override {
			/* glfwTerminate(); */ 
		}

};

#endif 
