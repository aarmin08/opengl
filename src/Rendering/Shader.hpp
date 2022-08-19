#pragma once

#include "glm/fwd.hpp"
#include <string>

class Shader {
private :
    const char *fragmentSource;
    const char *vertexSource;
    static unsigned int shaderProg;
public:
    unsigned int GetProg() { return shaderProg; }
    const char *GetFrag() { return fragmentSource; }
    const char *GetVertex() { return vertexSource; }

    Shader(const char *frag, const char *vertex) {
        this->fragmentSource = frag;
        this->vertexSource = vertex;
    }

    void CreateProgramAndBindShaders() const;
    void Bind() const;
    void Unbind() const;
    void UploadUniformMat4(const std::string& name, const glm::mat4 &mat);

private:
    uint32_t m_rendererId;
}; 
