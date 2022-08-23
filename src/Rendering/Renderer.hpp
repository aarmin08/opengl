#pragma once

#include "../World.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "Buffers.hpp"
#include "../Window.hpp"
#include "../Utils/Utils.hpp"
#include <GL/glew.h>
#include <iostream>
#include <memory>

#include "../Camera.hpp"
class Renderer {
private :
    std::unique_ptr<Shader> shader;
	std::unique_ptr<Shader> blueShader;
    Window *window;
    float r, g, b;

public :
    const char *vertexSource;
    const char *fragSource;
    std::unique_ptr<VAO> m_VertexArray;
    std::unique_ptr<VertexBuffer> m_VertexBuffer;
	
	std::unique_ptr<Camera> camera; 

    Renderer() {};

    Renderer(Window *win, Camera* camera) {
        vertexSource = Utils::vertexSrc;
        fragSource = Utils::fragmentSource;
        shader.reset(new Shader(fragSource, vertexSource));

        std::cout << vertexSource << std::endl;
        std::cout << fragSource << std::endl;

		this->camera.reset(camera); 
        /* gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)	; */
        // Load GL extensions using glad
        this->window = win;
    }


    void RendererStart(float r, float g, float b) {
		/* camera = Game::getCam(); */ 
        
        glViewport(0, 0, window->width, window->height);
        this->r = r;
        this->b = b;
        this->g = g;
		// put this in a triangle thingy maybe?? 

        /* glBindBuffer(GL_ARRAY_BUFFER, 0); */
    }

    void Render(World *world) {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glClearColor(r, g, b, 1.0f);

		std::cout << "Wa" << std::endl; 
        for (auto &entity: world->entities) {
            std::cout << world->entities.size() << std::endl;
            entity->Draw();
        }
		std::cout << "GAy" << std::endl; 
        window->SwapBuffers();
    }

    void Clean() {
        m_VertexArray->Clean();
        m_VertexBuffer->Clean();
        shader->Unbind();
    }

	Camera* getCamera() { return camera.get(); }; 
}; 
