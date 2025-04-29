//
// Created by Vinayak Regmi on 23/04/2025.
//
#include <GL/glew.h>
#include <iostream>

#ifndef TEXTURE_H
#define TEXTURE_H

namespace MeshHandling {

struct Texture {
    GLuint texture;
    GLint width, height, bitDepth;
};

} // MeshHandling

#endif //TEXTURE_H
