//
// Created by Vinayak Regmi on 27/04/2025.
//

#include "ShaderErrorHandler.h"

#include "../DebugLog/EngineLog.h"

namespace Render {
    void ShaderErrorHandler::Validate(GLuint &toValidate, ValidationTypes validationType) {
        GLint result=0;
        GLchar errorString[1024]={""};
        switch (validationType) {
            case(SHADER_PROGRAM_VALIDATION):
                //link validation
                    glLinkProgram(toValidate);
            glGetProgramiv(toValidate, GL_LINK_STATUS, &result);
            if (!result) {
                glGetProgramInfoLog(toValidate, sizeof(errorString), NULL, errorString);
                DebugLog::EngineLog::printError("Error Linking Shader");
                DebugLog::EngineLog::printError(errorString);
                DebugLog::EngineLog::setFlag(10);
            }

            //validate
            glValidateProgram(toValidate);
            glGetProgramiv(toValidate, GL_VALIDATE_STATUS, &result);
            if (!result) {
                glGetProgramInfoLog(toValidate, sizeof(errorString), NULL, errorString);
                DebugLog::EngineLog::printError("Error Validating Shader");
                DebugLog::EngineLog::printError(errorString);
                DebugLog::EngineLog::setFlag(10);
            }
            break;
            case(VERTEX_SHADER_VALIDATION):
            //compilation check
            glGetShaderiv(toValidate, GL_COMPILE_STATUS, &result);
            if (!result) {
                glGetShaderInfoLog(toValidate, sizeof(errorString), NULL, errorString);
                DebugLog::EngineLog::printError("Error Compiling the Vertex Shader");
                DebugLog::EngineLog::printError(errorString);
                DebugLog::EngineLog::setFlag(11);
            }
            break;
            case(FRAGMENT_SHADER_VALIDATION):
            //compilation check
            glGetShaderiv(toValidate, GL_COMPILE_STATUS, &result);
            if (!result) {
                glGetShaderInfoLog(toValidate, sizeof(errorString), NULL, errorString);
                DebugLog::EngineLog::printError("Error Compiling the Fragment Shader");
                DebugLog::EngineLog::printError(errorString);
                DebugLog::EngineLog::setFlag(11);
            }
            break;
        }
    }
} // Render