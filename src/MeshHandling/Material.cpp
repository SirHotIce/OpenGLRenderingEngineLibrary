//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "Material.h"


namespace MeshHandling {
    Material::Material(std::string diffuseMapFile, std::string normalMapFile,
        std::string roughnessMapFile, std::string metallicMapFile,
        Utils::ShaderTypes _shaderType) {

        diffusionMap= Importer::TextureImporter::loadTexture(diffuseMapFile);
        normalMap= Importer::TextureImporter::loadTexture(normalMapFile);
        roughnessMap= Importer::TextureImporter::loadTexture(roughnessMapFile);
        metallicMap= Importer::TextureImporter::loadTexture(metallicMapFile);
        shaderType= _shaderType;
        if(Render::ShaderCache::getShader(shaderType)!=-1) {
            GLuint shaderProgram= Render::ShaderCompiler::createProgram(Utils::GlobalConstants::phongVS, Utils::GlobalConstants::phongFS);
            Render::ShaderCache::addShader(shaderType, shaderProgram);
        }
    }

    Utils::ShaderTypes Material::getShaderType() {
        return shaderType;
    }

    //
    // //Set by material
    // uniform sampler2D albedoMap;
    // uniform sampler2D normalMap;
    // uniform sampler2D roughnessMap;
    // uniform sampler2D metallicMap;

    void Material::useMaterial() {

        int i=0;
        GLuint shaderProgram= Render::ShaderCache::getShader(shaderType);
        glActiveTexture(GL_TEXTURE0+i);
        GLuint textureLocation= glGetUniformLocation(shaderProgram, "albedoMap");
        GLuint normalLocation= glGetUniformLocation(shaderProgram, "normalMap");
        GLuint roughnessLocation= glGetUniformLocation(shaderProgram, "roughnessMap");
        GLuint metallicLocation= glGetUniformLocation(shaderProgram, "metallicMap");
        glBindTexture(GL_TEXTURE_2D, diffusionMap.texture);
        glUniform1i(textureLocation, i);
        i++;
        glActiveTexture(GL_TEXTURE0+i);
        glBindTexture(GL_TEXTURE_2D, normalMap.texture);
        glUniform1i(normalLocation, i);
        i++;
        glActiveTexture(GL_TEXTURE0+i);
        glBindTexture(GL_TEXTURE_2D, roughnessMap.texture);
        glUniform1i(roughnessLocation, i);
        i++;
        glActiveTexture(GL_TEXTURE0+i);
        glBindTexture(GL_TEXTURE_2D, metallicMap.texture);
        glUniform1i(metallicLocation, i);

    }

    void Material::unbindMaterial() {
        for(int i=0; i<5; i++) {
            glActiveTexture(GL_TEXTURE0+i);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
    }
} // MeshHandeling