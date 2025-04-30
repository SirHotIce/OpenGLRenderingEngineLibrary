//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Matrix/Transform.h"
#include "../MeshHandling/Material.h"
#include "../MeshHandling/Mesh.h"
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


#include "Light.h"

namespace Matrix {
    class Camera;
}

namespace Basic {

class GameObject {

private:
    std::string name;
    MeshHandling::Material material;

    MeshHandling::Mesh mesh;

    Matrix::Transform transform;

    GLuint VAO, VBO, EBO;

    void load();
public:

    GameObject(std::string name, std::string meshPath, std::string diffuseMapPath, std::string normalMapPath, std::string metallicMapPath, std::string roughnessMapPath, Utils::ShaderTypes shaderType);

    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();

    void bindUniforms(Matrix::Camera* camera, Light* light);
    void drawObject(Matrix::Camera *camera, Light *light);
    Matrix::Transform& getTransform();
};

} // Basic

#endif //GAMEOBJECT_H
