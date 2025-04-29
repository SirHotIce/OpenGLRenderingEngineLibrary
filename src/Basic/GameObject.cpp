//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "GameObject.h"

#include "../Importer/MeshImporter.h"
#include "../Matrix/Camera.h"

namespace Basic {


    GameObject::GameObject(std::string name, std::string meshPath, std::string diffuseMapPath,
                           std::string normalMapPath, std::string metallicMapPath, std::string roughnessMapPath,
                           Utils::ShaderTypes shaderType): material(diffuseMapPath, normalMapPath, metallicMapPath, roughnessMapPath,
                                          shaderType) {
        this->name = name;
        mesh = Importer::MeshImporter::importMesh(meshPath);
        load();
    }

    GLuint GameObject::getVAO() {
        return this->VAO;
    }

    GLuint GameObject::getVBO() {
        return this->VBO;
    }

    GLuint GameObject::getEBO() {
        return this->EBO;
    }

    void GameObject::load() {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size()* sizeof(unsigned int), mesh.indices.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size()*sizeof(MeshHandling::Vertex), mesh.vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0 ,3, GL_FLOAT, GL_FALSE, sizeof(MeshHandling::Vertex), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MeshHandling::Vertex), (void*)offsetof(MeshHandling::Vertex, TexCoords));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(MeshHandling::Vertex), (void*)offsetof(MeshHandling::Vertex, Normal));
        glEnableVertexAttribArray(2);
        glBindVertexArray(0);

    }
    /*
    uniform vec4 lightColor;
    uniform vec3 lightPosition;
    uniform vec3 lightDirection;
    uniform float ambientStrength;
    uniform float diffuseStrength;
    uniform vec3 cameraPosition;
    */
    void GameObject::bindUniforms(Matrix::Camera *camera, Light *light) {
        GLuint program= Render::ShaderCache::getShader(material.getShaderType());
        GLuint modelLocation= glGetUniformLocation(program, "model");
        GLuint viewLocation= glGetUniformLocation(program, "view");
        GLuint projectionLocation= glGetUniformLocation(program, "projection");
        glUniformMatrix4fv(modelLocation, 1,GL_FALSE, glm::value_ptr(transform.getModel()));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(camera->getProjectionMatrix()));
        material.useMaterial();
        GLuint lightColorLocation= glGetUniformLocation(program, "lightColor");
        GLuint lightPosLocation= glGetUniformLocation(program, "lightPosition");
        GLuint lightDirLocation= glGetUniformLocation(program, "lightDirection");
        GLuint ambStrLocation= glGetUniformLocation(program, "ambientStrength");
        GLuint diffStrLocation= glGetUniformLocation(program, "diffuseStrength");
        GLuint cameraPosLocation= glGetUniformLocation(program, "cameraPosition");
        glUniform4fv(lightColorLocation,1, glm::value_ptr(light->getColor()));
        glUniform3fv(lightDirLocation,1, glm::value_ptr(light->getDirection()));
        glUniform3fv(lightPosLocation,1, glm::value_ptr(light->getPosition()));
        glUniform1f(ambStrLocation, light->getAmbientStrength());
        glUniform1f(diffStrLocation, light->getDiffuseStrength());
        glUniform3fv(cameraPosLocation, 1, glm::value_ptr(camera->getPosition()));

    }

    void GameObject::drawObject(Matrix::Camera *camera, Light *light) {
        GLuint program= Render::ShaderCache::getShader(material.getShaderType());
        glUseProgram(program);
        bindUniforms(camera, light);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);//0 as indices are already bound
        glBindVertexArray(0);
        material.unbindMaterial();
        glUseProgram(0);
    }

    Matrix::Transform & GameObject::getTransform() {
        return transform;
    }
} // Basic