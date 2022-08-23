#include "Shader.hpp"
#include <GL/glew.h>

#include "../Utils/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

unsigned int Shader::shaderProg;

void Shader::CreateProgramAndBindShaders() const {
	std::cout << "Log at create \n"; 
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
	
	int success; 
	char infoLog[512]; 

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); 
	
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); 
		std::cout << infoLog << std::endl; 
		glDeleteShader(vertexShader); 
		exit(1); 
	}
	
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success); 

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); 
		std::cout << infoLog << "\n";
		glDeleteShader(fragmentShader); 
		exit(1); 
	}

    shaderProg = glCreateProgram();
    glAttachShader(shaderProg, vertexShader);
    glAttachShader(shaderProg, fragmentShader);
    glLinkProgram(shaderProg);
}

void Shader::Bind() const {
    glUseProgram(shaderProg);
}

void Shader::Unbind() const {
    glDeleteShader(shaderProg);
	glDeleteProgram(shaderProg);
}

void Shader::UploadUniformMat4(const std::string& name, const glm::mat4 &mat) {
	std::cout << "ga" << std::endl;
	std::cout << name << "," << shaderProg << std::endl; 
	GLint location = glGetUniformLocation(shaderProg, name.c_str()); 
	std::cout << mat.length()  << std::endl;
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	std::cout << "waaa" << std::endl;

	std::cout << location << std::endl; 
}
