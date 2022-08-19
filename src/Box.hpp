#pragma once 

#include "Camera.hpp"
#include "Component.hpp"
#include "Rendering/Shader.hpp"
#include "Rendering/VAO.hpp"
#include "Rendering/Buffers.hpp"

#include <GL/glew.h>

#include <memory>
#include <vector>

#include "Game.hpp"
class Box : Component {
	private : 
		float x, y;
		std::unique_ptr<Shader> shader;
		std::unique_ptr<VAO> m_VertexArray; 
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		
		std::unique_ptr<Camera> camera;

		const char* frag = Utils::fragmentSource;
		const char* vertex = Utils::vertexSrc; 
	public :
		Box() {
		}
		
		// to be run in render start
		void Start() override {
			shader.reset(new Shader(frag, vertex)); 
			camera.reset(Game::camera); 

			float verticees[] = {
			 // first triangle
				 0.5f,  0.5f, 0.0f,  // top right
				0.5f, -0.5f, 0.0f,  // bottom right
				-0.5f,  0.5f, 0.0f,  // top left 
				// second triangle
				0.5f, -0.5f, 0.0f,  // bottom right
				-0.5f, -0.5f, 0.0f,  // bottom left
				-0.5f,  0.5f, 0.0f   // top left
			};
			shader->CreateProgramAndBindShaders();
			m_VertexArray.reset(m_VertexArray->Create());
			m_VertexBuffer.reset(m_VertexBuffer->Create());
			m_VertexArray->Bind();
			m_VertexBuffer->Bind(verticees, sizeof(verticees));
			m_VertexArray->Unbind(3);
			m_VertexBuffer->Unbind();
		}; 	
		// To be run in the update function 
		void Update() override {
			shader->Bind();
			m_VertexArray->Bind();
			shader->UploadUniformMat4("u_viewProjection", Game::camera->GetProjViewMatrix());
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}; 
};
