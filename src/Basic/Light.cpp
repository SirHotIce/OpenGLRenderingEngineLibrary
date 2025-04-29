//
// Created by Vinayak Regmi on 28/04/2025.
//

#include "Light.h"

namespace Basic {
    glm::vec3 Light::getColor() {
        return color;
    }

    glm::vec3 Light::getPosition() {
        return position;
    }

    glm::vec3 Light::getDirection() {
        return direction;
    }

    float Light::getAmbientStrength() {
        return ambientStrength;
    }

    float Light::getDiffuseStrength() {
        return diffuseStrength;
    }



    void Light::setColor( glm::vec3 color) {
        this->color = color;
    }

    void Light::setPosition( glm::vec3 position) {
        this->position = position;
    }

    void Light::setDirection( glm::vec3 direction) {
        this->direction = direction;
    }

    void Light::setAmbientStrength(float ambient_strength) {
        this->ambientStrength = ambient_strength;
    }

    void Light::setDiffuseStrength(float diffuse_strength) {
        this->diffuseStrength = diffuse_strength;
    }
    
} // Basic