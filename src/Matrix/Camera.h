//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Utils/Vector3.h"

namespace Matrix {

class Camera {
private:
    float fov;
    float aspect;
    float near;
    float far;


    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;

    glm::mat4 view;
    glm::mat4 projection;


    public:
    Camera(float fov, float aspect, float near, float far);

    void setFov(float fov);
    void setAspect(float aspect);
    void setNear(float near);
    void setFar(float far);
    void setPosition(float x, float y, float z);
    void setRotation(float pitch, float yaw);
    glm::mat4& getViewMatrix();
    glm::mat4& getProjectionMatrix();

    glm::vec3 getPosition();
    Utils::Vector3 getPositionOut();
    Utils::Vector3 getRotationOut();
};

} // Matrix

#endif //CAMERA_H
