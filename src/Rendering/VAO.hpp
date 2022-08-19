#pragma once

class VAO {
private :
public :
    static unsigned int i;

    void Bind();

    void Unbind(int indices);

    void Clean();

    VAO *Create();
}; 
