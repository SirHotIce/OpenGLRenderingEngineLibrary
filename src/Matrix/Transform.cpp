//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "Transform.h"

#include <ext/matrix_transform.hpp>

namespace Matrix {
    Transform::Transform() {
        position= glm::vec3(0,0,0);
        rotation= glm::vec3(0,0,0);
        scale= glm::vec3(1,1,1);
        model= glm::mat4(1);
    }

    void Transform::setPosition(float x, float y, float z) {
        position.x = x;
        position.y = y;
        position.z = z;
    }

    void Transform::setRotation(float x, float y, float z) {
        rotation.x = glm::radians(x);
        rotation.y = glm::radians(y);
        rotation.z = glm::radians(z);
    }

    void Transform::setScale(float x, float y, float z) {
        scale.x = x;
        scale.y = y;
        scale.z = z;
    }

    glm::mat4 & Transform::getModel() {
        model= glm::mat4(1);

        model= glm::translate(model, position);
        model= glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
        model= glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
        model= glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
        model= glm::scale(model, scale);

        return model;
    }

    Utils::Vector3 Transform::getPosition() {
        Utils::Vector3 vec{};
        vec.x = position.x;
        vec.y = position.y;
        vec.z = position.z;
        return vec;
    }

    Utils::Vector3 Transform::getRotation() {
        Utils::Vector3 vec{};
        vec.x = glm::degrees(rotation.x);
        vec.y = glm::degrees(rotation.y);
        vec.z = glm::degrees(rotation.z);
        return vec;
    }

    Utils::Vector3 Transform::getScale() {
        Utils::Vector3 vec{};
        vec.x = scale.x;
        vec.y = scale.y;
        vec.z = scale.z;
        return vec;
    }
} // Matrix