#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float left, float right, float top, float bottom) :
        projectionMatrix(glm::ortho(left, right, bottom, top)), viewMatrix(1) {
    viewProjectionMatrix = projectionMatrix * viewMatrix;
}

void Camera::RecalculateViewMatrix() {
    glm::mat4 transform =
            glm::translate(glm::mat4(1.0f), mPosition)
            * glm::rotate(glm::mat4(1.0f), mRotation, glm::vec3(0, 0, 1));
    viewMatrix = glm::inverse(transform);
    viewProjectionMatrix = projectionMatrix * viewMatrix;
}
