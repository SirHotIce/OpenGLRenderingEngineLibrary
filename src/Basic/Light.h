//
// Created by Vinayak Regmi on 28/04/2025.
//

#ifndef LIGHT_H
#define LIGHT_H
#include <glm/glm.hpp>

#include "../Utils/GlobalConstants.h"
#include "../Utils/ShaderTypes.h"

namespace Basic {
    class Light {
    private:
        glm::vec3 color;
        glm::vec3 position;
        glm::vec3 direction;
        float ambientStrength;
        float diffuseStrength;

    public:
        Light(const glm::vec3 &color, const glm::vec3 &position, const glm::vec3 &direction, float ambient_strength,
            float diffuse_strength)
            : color(color),
              position(position),
              direction(direction),
              ambientStrength(ambient_strength),
              diffuseStrength(diffuse_strength) {
        }

        glm::vec3 getColor();
        glm::vec3 getPosition();
        glm::vec3 getDirection();
        float getAmbientStrength();
        float getDiffuseStrength();

        void setColor( glm::vec3 color);
        void setPosition( glm::vec3 position);
        void setDirection( glm::vec3 direction);
        void setAmbientStrength(float ambient_strength);
        void setDiffuseStrength(float diffuse_strength);

    };
} // Basic

#endif //LIGHT_H
