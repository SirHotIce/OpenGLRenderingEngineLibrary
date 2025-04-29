//
// Created by Vinayak Regmi on 27/04/2025.
//

#ifndef SHADERCACHE_H
#define SHADERCACHE_H
#include <unordered_map>
#include <GL/glew.h>

#include "../Utils/ShaderTypes.h"

namespace Render {
    class ShaderCache {

    private:
        static inline std::unordered_map<int, GLuint> cache={
            {0,static_cast<GLuint>(-1)}
        };
    public:
        static GLuint getShader(Utils::ShaderTypes type);
        static void addShader(Utils::ShaderTypes type, GLuint shader);

    };
}


#endif //SHADERCACHE_H
