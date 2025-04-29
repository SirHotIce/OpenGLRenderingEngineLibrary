//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "Camera.h"

namespace Matrix {
    Camera::Camera(float fov, float aspect, float near, float far) {
        this->fov = glm::radians(fov);
        this->aspect = aspect;
        this->near = near;
        this->far = far;

        position = glm::vec3(0, 0, 0);
        worldUp = glm::vec3(0, 1, 0);
        pitch = glm::radians(180.0f);
        yaw = glm::radians(90.0f);

        view= glm::mat4(1.0f);
        projection = glm::mat4(1.0f);
    }

    void Camera::setFov(float fov) {
        this->fov = glm::radians(fov);
    }

    void Camera::setAspect(float aspect) {
        this->aspect = aspect;
    }

    void Camera::setNear(float near) {
        this->near = near;
    }

    void Camera::setFar(float far) {
        this->far = far;
    }

    void Camera::setPosition(float x, float y, float z) {
        this->position = glm::vec3(x, y, z);
    }

    void Camera::setRotation(float pitch, float yaw) {
        this->pitch = glm::radians(pitch);
        this->yaw = glm::radians(yaw);
    }

    glm::mat4 & Camera::getViewMatrix() {
        view= glm::mat4(1.0f);
        float x= cos(pitch)*cos(yaw);
        float y= sin(pitch);
        float z= cos(pitch)*sin(yaw);

        front = glm::vec3(x, y, z);
        front = glm::normalize(front);
        right= glm::cross(front, worldUp);
        right= normalize(right);
        up= glm::cross(right, front);
        up= normalize(up);

        view = glm::lookAt(position, position + front, up);

        return view;
    }

    glm::mat4 & Camera::getProjectionMatrix() {
        projection = glm::mat4(1.0f);
        projection= glm::perspective(fov, aspect, near, far);
        return projection;
    }

    Utils::Vector3 Camera::getPositionOut() {
        Utils::Vector3 vec{};
        vec.x = position.x;
        vec.y = position.y;
        vec.z = position.z;
        return vec;
    }

    Utils::Vector3 Camera::getRotationOut() {
        Utils::Vector3 vec{};
        vec.x = glm::degrees(pitch);
        vec.y = glm::degrees(yaw);
        vec.z = 0.0f;

        return vec;

    }

    glm::vec3 Camera::getPosition() {
        return position;
    }
} // Matrix