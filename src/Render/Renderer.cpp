//
// Created by Vinayak Regmi on 28/04/2025.
//

#include "Renderer.h"

namespace Render {


    void Renderer::setFlags() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    }

    void Renderer::glfwInitialize() {
        if (!glfwInit()) {
            DebugLog::EngineLog::printError("GLFW initialization failed");
            DebugLog::EngineLog::setFlag(5);
            exit(EXIT_FAILURE);
        }
    }

    void Renderer::glewInitialize() {
        if (glewInit()!= GLEW_OK) {
            DebugLog::EngineLog::printError("GLEW initialization failed");
            DebugLog::EngineLog::setFlag(6);
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_ARB_arrays_of_arrays);

    }
    void Renderer::initialize() {
        glfwInitialize();
        setFlags();
        window = glfwCreateWindow(1, 1, "OpenGL Renderer", NULL, NULL);
        if (!window) {
            DebugLog::EngineLog::printError("GLFW initialization failed");
            DebugLog::EngineLog::setFlag(7);
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glViewport(0,0, 1, 1);
        glewInitialize();
    }

    void Renderer::miscInitialize() {}

    Renderer::Renderer(): dirLight(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 1.0f),0.35f, 0.65f) {
        initialize();
    }

    void Renderer::setClearColor(float r, float g, float b) {
        clearColor[0]=r;
        clearColor[1]=g;
        clearColor[2]=b;

    }

    std::vector<unsigned char> Renderer::render(Basic::GameObject** game_objects, int count,Matrix::Camera *camera, Frame* frame) {

        glfwPollEvents();
        glEnable(GL_DEPTH_TEST|GL_CULL_FACE);
        frame->attach();
        glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        DebugLog::EngineLog::print("Rendering Objects: " +std::to_string(count) );
        for(int i=0; i<count; i++) {
            game_objects[i]->drawObject(camera, &dirLight);
        }
        DebugLog::EngineLog::print("Rendering Done");
        frame->detach();
        return  frame->getPixelData();

    }
} // Render