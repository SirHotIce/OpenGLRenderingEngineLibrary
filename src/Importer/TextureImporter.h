//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H
#include "../MeshHandling/Texture.h"
#include"../Utils/stb_image.h"

namespace Importer {

class TextureImporter {

public:
    static MeshHandling::Texture loadTexture(const std::string& path);
};

} // Importer

#endif //TEXTUREIMPORTER_H
