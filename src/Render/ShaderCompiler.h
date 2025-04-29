//
// Created by Vinayak Regmi on 27/04/2025.
//

#ifndef SHADERCOMPILER_H
#define SHADERCOMPILER_H
#include <string>
#include <GL/glew.h>

namespace Render {

class ShaderCompiler {

public:
    static GLuint createProgram(std::string vertFile, std::string fragFile);
    static void attachShader(std::string fileName, GLenum shaderType, GLuint& shaderID);
    static std::string  readFile(std::string fileName);
};

} // Render

#endif //SHADERCOMPILER_H
