//
// Created by Vinayak Regmi on 27/04/2025.
//

#include "ShaderCache.h"
namespace Render {
    GLuint ShaderCache::getShader(Utils::ShaderTypes type) {
        return cache[type];
    }

    void ShaderCache::addShader(Utils::ShaderTypes type, GLuint shader) {
        cache[type] = shader;
    }
}
