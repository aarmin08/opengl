#include "VAO.hpp"
#include <GL/glew.h>

#include <iostream>

unsigned int VAO::i;

VAO *VAO::Create() {
    std::cout << "why do we exist \n";
    glGenVertexArrays(1, &i);
    std::cout << "sssss \n";
    return this;
}

void VAO::Bind() {
    glBindVertexArray(i);
}

void VAO::Unbind(int indices) {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, indices * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
}

void VAO::Clean() {
    glDeleteVertexArrays(1, &i);
}
