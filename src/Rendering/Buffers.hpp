#pragma once

#include <iostream>

class VertexBuffer {
private :
public:
    static unsigned int id;

    void Clean();

    void Bind(float *vertices, uint32_t size);

    void Unbind();

    VertexBuffer *Create();
};	

