//
// Created by Vinayak Regmi on 27/04/2025.
//

#include "ShaderCompiler.h"

#include <iostream>
#include <fstream>
#include "ShaderErrorHandler.h"
#include "../DebugLog/EngineLog.h"

namespace Render {
    GLuint ShaderCompiler::createProgram(std::string vertFile, std::string fragFile) {
        GLuint program = glCreateProgram();
        if (program == 0) {
            DebugLog::EngineLog::printError("Error creating shader program");
            DebugLog::EngineLog::setFlag(10);
        }
        attachShader(vertFile, GL_VERTEX_SHADER, program);
        attachShader(fragFile, GL_FRAGMENT_SHADER, program);
        ShaderErrorHandler::Validate(program, SHADER_PROGRAM_VALIDATION);
        return program;
    }

    void ShaderCompiler::attachShader(std::string fileName, GLenum shaderType, GLuint& shaderProgram) {
        GLuint shaderID = glCreateShader(shaderType);
        if (shaderProgram == 0) {
            DebugLog::EngineLog::printError("Error creating shader");
            DebugLog::EngineLog::setFlag(11);
        }
        std::string fileContents= readFile(fileName);
        const char* readData=  fileContents.c_str();
        const GLchar* shaderSource= readData;
        const GLint shaderLength= std::strlen(shaderSource);
        glShaderSource(shaderID, 1, &shaderSource, &shaderLength);
        glCompileShader(shaderID);
        ShaderErrorHandler::Validate(shaderID,(shaderType==GL_VERTEX_SHADER)?VERTEX_SHADER_VALIDATION:FRAGMENT_SHADER_VALIDATION);
        glAttachShader(shaderProgram, shaderID);

    }

    std::string ShaderCompiler::readFile(std::string fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            DebugLog::EngineLog::printError("Couldn't open shader file");
            DebugLog::EngineLog::setFlag(11);
        }
        std::string line, data;
        while (std::getline(file, line)) {
            data+=line+="\n";
        }
        file.close();

        return  data;
    }
} // Render