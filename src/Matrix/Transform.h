//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glm/glm.hpp>

#include "../Utils/Vector3.h"

namespace Matrix {

class Transform {
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat4 model;

    public:
    Transform();
    glm::mat4& getModel();
    void setPosition(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);

    Utils::Vector3 getPosition();
    Utils::Vector3 getRotation();
    Utils::Vector3 getScale();

};

} // Matrix

#endif //TRANSFORM_H
