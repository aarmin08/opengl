#pragma once

#include <glm/glm.hpp>

class Camera {
private :
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 viewProjectionMatrix;

    glm::vec3 mPosition;
    float mRotation = 0.0f;
private :
    void RecalculateViewMatrix();

public :
    Camera(float left, float right, float bottom, float top);

    const glm::vec3 &GetPos() const { return mPosition; }

    float GetRotation() const { return mRotation; }

    void SetPosition(const glm::vec3 &position) {

        mPosition = position;
        RecalculateViewMatrix();
    }

    void SetRotation(float rot) {
        mRotation = rot;
        RecalculateViewMatrix();
    }

    const glm::mat4 &GetProjMatrix() { return projectionMatrix; }
    const glm::mat4 &GetViewMatrix() { return viewMatrix; }
    const glm::mat4 &GetProjViewMatrix() { return viewProjectionMatrix; }

}; 
