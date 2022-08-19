#include "OpenGLBuffer.hpp"
#include <GL/glew.h>

OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size) {
    glCreateBuffers(1, &m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    std::cout << "wwwww" << std::endl;
};

OpenGLVertexBuffer::~OpenGLVertexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void OpenGLVertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void OpenGLVertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

