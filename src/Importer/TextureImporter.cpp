//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "TextureImporter.h"

#include "../DebugLog/EngineLog.h"

namespace Importer {
    MeshHandling::Texture TextureImporter::loadTexture(const std::string &path) {
        MeshHandling::Texture tex;
        unsigned char* texData= stbi_load(path.c_str(),&tex.width, &tex.height, &tex.bitDepth, STBI_rgb_alpha);
        if (!texData) {
            DebugLog::EngineLog::printWarning("Failed to load texture");
        }
        glGenTextures(1, &tex.texture);
        glBindTexture(GL_TEXTURE_2D, tex.texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width, tex.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(texData);

        return tex;
    }
} // Importer