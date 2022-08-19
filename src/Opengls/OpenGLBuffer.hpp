#pragma once

#include "../Rendering/Buffers.hpp"

class OpenGLVertexBuffer : public VertexBuffer {
public :
    OpenGLVertexBuffer(float *vertices, uint32_t size);

    virtual ~OpenGLVertexBuffer();

    virtual void Bind() const;

    virtual void Unbind() const;

private :
    uint32_t m_RendererID;
};

