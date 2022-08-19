#include "Buffers.hpp"
#include <GL/glew.h>

unsigned int VertexBuffer::id;

VertexBuffer *VertexBuffer::Create() {
    std::cout << "trolling" << std::endl;
    glGenBuffers(1, &id);
    return this;
}

void VertexBuffer::Bind(float *vertices, uint32_t size) {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    std::cout << id << std::endl;
}

void VertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    std::cout << "gaming" << std::endl;
}

void VertexBuffer::Clean() {
    glDeleteBuffers(1, &id);
}
