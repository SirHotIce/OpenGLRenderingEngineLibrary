//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include "Texture.h"
#include "../Utils/ShaderTypes.h"

#include "../Importer/TextureImporter.h"
#include "../Render/ShaderCache.h"
#include "../Render/ShaderCompiler.h"
#include "../Utils/GlobalConstants.h"

namespace MeshHandling {

class Material {
    Texture diffusionMap{};
    Texture normalMap{};
    Texture roughnessMap{};
    Texture metallicMap{};
    Texture aoMap{};
    Utils::ShaderTypes shaderType;

public:
    Material(std::string diffuseMapFile, std::string normalMapFile, std::string roughnessMapFile, std::string metallicMapFile, Utils::ShaderTypes _shaderType);
    void useMaterial();
    void unbindMaterial();
    Utils::ShaderTypes getShaderType();

};

} // MeshHandeling

#endif //MATERIAL_H
