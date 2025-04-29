//
// Created by Vinayak Regmi on 27/04/2025.
//

#ifndef SHADERERRORHANDLER_H
#define SHADERERRORHANDLER_H
#include <GL/glew.h>

namespace Render {

    enum ValidationTypes {
        SHADER_PROGRAM_VALIDATION,
        VERTEX_SHADER_VALIDATION,
        FRAGMENT_SHADER_VALIDATION,
    };
class ShaderErrorHandler {
public:
    static void Validate(GLuint& toValidate, ValidationTypes validationType);
};

} // Render

#endif //SHADERERRORHANDLER_H
